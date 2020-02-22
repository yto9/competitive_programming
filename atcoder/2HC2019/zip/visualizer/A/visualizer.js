"use strict"

const DEPOT_INDEX = 1;

const FPS_MIN = 1;
const FPS_MAX = 60;
const DEFAULT_FPS = 10;

const INF = 1000000000;

// FIXME
const V_MIN = 1;
const V_MAX = 400;
const T_MIN = 1;
const T_MAX = 10000;
const C_MIN = 1;
const C_MAX = 300;
const NUM_OF_ORDERS_MIN = 0;
const NUM_OF_ORDERS_MAX = 1;

// ファイル選択後にファイル名を表示 (jQuery の存在前提)
$(document).on('change', ':file', function() {
    let input = $(this),
    numFiles = input.get(0).files ? input.get(0).files.length : 1,
    label = input.val().replace(/\\/g, '/').replace(/.*\//, '');
    input.parent().parent().next(':text').val(label);
});

$(document).on('click', '#output-file-select-textbox', function() {
    $('#output-file-select-button').trigger('click');
});

$(document).on('click', '#input-file-select-textbox', function() {
    $('#input-file-select-button').trigger('click');
});

$(document).on('click', '#show-error-message-textbox', function() {
    document.getElementById('show-error-message-checkbox').checked ^= true;
});

// 繋がったデータを改行で区切り、空行は無視
const splitDataByEoln = function(data) {
    const lines = data.split(/\r?\n/g);
    return lines.filter(line => line.length !== 0);
};

// 改行で区切られたデータの各行を空白ごとに区切る
const splitData = function(lines) {
    let res = [];
    lines.forEach(line => res.push(line.split(' ')));
    return res;
};

const clamp = function(value, min, max) {
    return Math.max(min, Math.min(value, max));
}

// 入力・出力ファイルを受け取り、各ステップごとに分けて配列にする
let FileManager = (function() {
    const FileManager = function() {
	const this_ = this;
	this.outputData = document.getElementById('output-file-select-button');
	this.inputData = document.getElementById('input-file-select-button');
	this.reloadFilesClosure = function() { this_.reloadFiles(); };

	this.outputData.addEventListener('change', this.reloadFilesClosure);
	this.inputData.addEventListener('change', this.reloadFilesClosure);
    };
    
    // ファイルの読み込み
    FileManager.prototype.loadFile = function(file, callback) {
	let reader = new FileReader();
	reader.onloadend = function() {
	    const data = splitDataByEoln(reader.result);
	    callback(data);
	};
	reader.readAsText(file);
    };
    
    // Output, Input データのリロード
    FileManager.prototype.reloadFiles = function() {
	if(!this.outputData.files || this.outputData.files.length === 0) return;
	if(!this.inputData.files || this.inputData.files.length === 0) return;

	const this_ = this;
	this.loadFile(this.outputData.files[0], function(outputStream) {
	    this_.loadFile(this_.inputData.files[0], function(inputStream) {
		if(this_.callback !== undefined) {
		    this_.callback(outputStream, inputStream);
		}
	    });
	});
    };

    return FileManager;
}());

let UserInterface = (function() {
    const UserInterface = function() {
	this.logger = new Logger();
	this.time = 0;
	this.isPlaying = false;
	this.isValidState = false;
	this.fps = DEFAULT_FPS;
	this.visualizer;
	this.numOfMoves;
	this.intervalID;

	const this_ = this;
	this.clickNextStateBtnClosure = function() { this_.clickNextStateBtn(); };
	this.clickPrevStateBtnClosure = function() { this_.clickPrevStateBtn(); };
	this.clickFirstStateBtnClosure = function() { this_.clickFirstStateBtn(); };
	this.clickLastStateBtnClosure = function() { this_.clickLastStateBtn(); };
	this.clickPlayBtnClosure = function() { this_.clickPlayBtn(); };
	this.stopAtLastStateClosure = function() { this_.stopAtLastState(); };
	this.inputFpsWindowClosure = function() { this_.inputFpsWindow(); };
	this.inputSeekNumberClosure = function() { this_.inputSeekNumber(); };
	this.inputSeekRangeClosure = function() { this_.inputSeekRange(); };
	
	let nextStateBtn = document.getElementById('next-button');
	nextStateBtn.addEventListener('click', this.clickNextStateBtnClosure);

	let prevStateBtn = document.getElementById('prev-button');
	prevStateBtn.addEventListener('click', this.clickPrevStateBtnClosure);

	let firstStateBtn = document.getElementById('first-button');
	firstStateBtn.addEventListener('click', this.clickFirstStateBtnClosure);

	let lastStateBtn = document.getElementById('last-button');
	lastStateBtn.addEventListener('click', this.clickLastStateBtnClosure);

	let playBtn = document.getElementById('play-button');
	playBtn.addEventListener('click', this.clickPlayBtnClosure);

	// play のまま最後まで到達したとき
	this.stopAtLastStateClosureID = setInterval(this.stopAtLastStateClosure, 200);

	this.fpsWindow = document.getElementById('fps-window');
	this.fpsWindow.addEventListener('input', this.inputFpsWindowClosure);

	this.seekNumber = document.getElementById('seek-number');
	this.seekNumber.addEventListener('input', this.inputSeekNumberClosure);

	this.seekRange = document.getElementById('seek-range');
	this.seekRange.addEventListener('input', this.inputSeekRangeClosure);

	this.operationWindow = document.getElementById('operation-window');
    };

    UserInterface.prototype.discardPrevSession = function() {
	this.stop();
	this.isValidState = false;
	document.getElementById('overlay-field').style.display = 'none';
    };
    
    UserInterface.prototype.init = function() {
	this.setNumOfMoves(this.visualizer.outputBlock.length);
	this.time = 0;
	this.isPlaying = true;
	this.operationWindow.value = "";
	this.isValidState = true;

	this.stop();
	this.play();
    };

    UserInterface.prototype.play = function() {
	if(this.visualizer === undefined || !this.isValidState) return;

	// 最初に戻す
	if(this.time + 1 == this.numOfMoves) {
	    this.setTime(0);
	}
	
	let playBtn = document.getElementById('play-button');
	playBtn.value = 'stop';

	let playBtnIcon = document.getElementById('play-button-icon');
	playBtnIcon.classList.remove('fa-play');
	playBtnIcon.classList.add('fa-stop');

	const this_ = this;
	this.isPlaying = true;
	this.intervalID = setInterval(function() {
	    if(this_.time + 1 >= this_.numOfMoves) return;
	    this_.setTime(this_.time + 1);
	}, 1000.0 / this.fps);
    };

    UserInterface.prototype.stop = function() {
	let playBtn = document.getElementById('play-button');
	playBtn.value = 'play';

	let playBtnIcon = document.getElementById('play-button-icon');
	playBtnIcon.classList.remove('fa-stop');
	playBtnIcon.classList.add('fa-play');
	
	this.isPlaying = false;
	clearInterval(this.intervalID);
    }
    
    UserInterface.prototype.setTime = function(time) {
	if(this.visualizer === undefined || !this.isValidState) return;
	
	this.time = time;
	this.visualizer.modifyTime(this.time);
	this.logger.changeLogMsg(this.visualizer.inputBlock[this.time], this.time);
	
	this.seekNumber.value = time;
	this.seekRange.value = time;

	const command = this.visualizer.outputBlock[this.time];
	let commandStr = (command === -1 ? '[STAY]' : '[MOVE] ' + command);
	if(time === 0) commandStr = '-';
	this.operationWindow.value = commandStr;
    };

    UserInterface.prototype.clickNextStateBtn = function() {
	if(this.time + 1 == this.numOfMoves) return;
	this.stop();
	this.setTime(this.time + 1);
    };

    UserInterface.prototype.clickPrevStateBtn = function() {
	if(this.time == 0) return;
	this.stop();
	this.setTime(this.time - 1);
    };

    UserInterface.prototype.clickFirstStateBtn = function() {
	this.stop();
	this.setTime(0);
    };

    UserInterface.prototype.clickLastStateBtn = function() {
	this.stop();
	this.setTime(this.numOfMoves - 1);
    };

    UserInterface.prototype.clickPlayBtn = function() {
	this.isPlaying ^= true;
	if(this.isPlaying) this.play();
	else this.stop();
    };

    UserInterface.prototype.stopAtLastState = function() {
	if(this.time + 1 >= this.numOfMoves) {
	    this.stop();
	}
    };
    
    UserInterface.prototype.inputFpsWindow = function() {
	let newFps = clamp(parseInt(this.fpsWindow.value), FPS_MIN, FPS_MAX);
	if(isNaN(newFps) || isNaN(parseInt(this.fpsWindow.value))) {
	    newFps = DEFAULT_FPS;
	    this.fpsWindow.value = '';
	}
	else {
	    this.fpsWindow.value = newFps;
	}
	
	this.fps = newFps;
	if(this.isPlaying) {
	    clearInterval(this.intervalID);
	    this.play();
	}
    };

    UserInterface.prototype.inputSeekNumber = function() {
	let newFrame = clamp(parseInt(this.seekNumber.value), 0, this.numOfMoves - 1);
	if(isNaN(newFrame) || isNaN(parseInt(this.seekNumber.value))) {
	    newFrame = 0;
	}
	
	this.setTime(newFrame);
    };

    UserInterface.prototype.inputSeekRange = function() {
	let newFrame = clamp(parseInt(this.seekRange.value), 0, this.numOfMoves - 1);
	if(isNaN(newFrame) || isNaN(parseInt(this.seekRange.value))) {
	    newFrame = 0;
	}

	this.setTime(newFrame);
    }

    UserInterface.prototype.setNumOfMoves = function(maxStep) {
	this.numOfMoves = maxStep;
	this.setSeekRange(maxStep);
    }
    
    UserInterface.prototype.setSeekRange = function(maxStep) {
	this.seekRange.max = maxStep - 1;
	this.seekNumber.max = maxStep - 1;
    }

    return UserInterface;
}());

let Parser = (function() {
    const Parser = function(data, name) {
	this.dataStream = splitData(data);
	this.x = 0, this.y = 0;
	this.name = name;
	this.hasError = false;
    };

    Parser.prototype.isEoln = function() {
	return this.x < this.dataStream.length && this.y === this.dataStream[this.x].length;
    };

    Parser.prototype.isEof = function() {
	return this.x === this.dataStream.length && this.y === 0;
    };

    Parser.prototype.readInt = function(...args) {
	if(this.isEoln()) this.sendError('expected: integer, found: end of line');
	if(this.isEof()) this.sendError('expected: integer, found: end of file');

	const word = this.readWord();
	if(!word.match(new RegExp(/[+-]?\d+/))) {
	    this.sendError('expected: integer, found: ' + word);
	}

	switch(args.length) {
	case 2:
	    const intInput = parseInt(word);
	    if(intInput < parseInt(args[0]) || parseInt(args[1]) < intInput) {
		this.sendError('expected: integer [' + args[0] + ', ' + args[1] + '], found: ' + word);
	    }
	    return intInput;
	case 0:
	    return parseInt(word);
	default:
	    this.sendError('internal error: invalid arguments of "readInt()"');
	}
    };

    Parser.prototype.readWord = function() {
	if(this.isEoln()) this.sendError('expected: word, found: end of line');
	if(this.isEof()) this.sendError('expected: word, found: end of file');

	return this.dataStream[this.x][this.y++];
    };

    Parser.prototype.readEoln = function() {
	if(this.isEof()) this.sendError('expected: end of line, found: end of file');
	if(!this.isEoln()) {
	    const word = this.readWord();
	    this.sendError('expected: end of line, found: ' + word);
	}
	this.x++; this.y = 0;
    };

    Parser.prototype.readEof = function() {
	if(this.isEoln()) this.sendError('expected: end of file, found: end of line');
	if(!this.isEof()) {
	    const word = this.readWord();
	    this.sendError('expected: end of file, found: ' + word);
	}
    };

    Parser.prototype.sendError = function(msg, line = -1) {
	this.hasError = true;
	if(line < 0) line = this.x + 1;
	msg = this.name + ': line ' + line + ': ' + msg;
	if(!document.getElementById('show-error-message-checkbox').checked) {
	    alert(msg);
	}
	throw new Error(msg);
    };

    return Parser;
}());

let Visualizer = (function() {
    const Visualizer = function(outputData, inputData) {
	this.outputParser = new Parser(outputData, '<output-file>');
	this.inputParser = new Parser(inputData, '<input-file>');

	// 前に描画されていたグラフの情報を消す
	const container = document.getElementById('graph-field');
	this.network = new vis.Network(container, {});	
	
	// グラフを読む
	this.V = this.inputParser.readInt(V_MIN, V_MAX);
	const E_MIN = this.V - 1, E_MAX = this.V * (this.V - 1) / 2;
	this.E = this.inputParser.readInt(E_MIN, E_MAX);
	this.inputParser.readEoln();

	let rawNodes = Array.from({length: this.V}, (v, k) => {
	    return {id: k+1, label: (k+1).toString(), shape: 'box'};
	});

	let rawEdges = [];
	this.edgeCostOracle = {};
	for(let i=0; i<this.E; i++) {
	    const u = this.inputParser.readInt(1, this.V);
	    const v = this.inputParser.readInt(1, this.V);
	    const c = this.inputParser.readInt(C_MIN, C_MAX);
	    this.inputParser.readEoln();

	    rawEdges.push({from: u, to: v, label: c.toString()});
	    this.edgeCostOracle[ [u, v] ] = c;
	    this.edgeCostOracle[ [v, u] ] = c;
	}

	this.T = this.inputParser.readInt(T_MIN, T_MAX);
	this.inputParser.readEoln();

	this.inputBlock = [];
	for(let i=0; i<=this.T; i++) this.inputBlock.push([ [], [], [] ]);
	this.numOfOrder = 0;

	for(let t=0; t<this.T; t++) {
	    const numOfNewOrders = this.inputParser.readInt(NUM_OF_ORDERS_MIN, NUM_OF_ORDERS_MAX);
	    this.inputParser.readEoln();

	    let newOrderList = [];
	    for(let i=0; i<numOfNewOrders; i++) {
		this.numOfOrder++;
		const id = this.inputParser.readInt(this.numOfOrder, this.numOfOrder);
		const vertex = this.inputParser.readInt(1, this.V);
		this.inputParser.readEoln();
		newOrderList.push([id, vertex, t]);
	    }
	    this.inputBlock[t][0] = newOrderList;
	}
	this.inputParser.readEof();

	this.outputBlock = [-1];
	for(let i=0; i<this.T; i++) {
	    const command = this.outputParser.readInt(-1, this.V);
	    if(command === 0) {
		this.outputParser.sendError('invalid output');
	    }
	    this.outputParser.readEoln();
	    this.outputBlock.push(command);
	}
	this.outputParser.readEof();
	
	// 各時間ごとに車がどこにいるか計算
	this.carPosition = this.calculateCarPosition();

	// グラフを可視化
	const graphData = {
	    nodes: new vis.DataSet(rawNodes),
	    edges: new vis.DataSet(rawEdges)
	};
	const graphOptions = {
	    nodes: {
	    },
	    edges: {
		smooth: false
	    }
	};
	this.network = new vis.Network(container, graphData);
	this.network.setOptions(graphOptions);
	
	// 車を描画
	const this_ = this;
	this.currentTime = 0;
	this.network.on('afterDrawing', function(ctx) {	
	    this_.drawCar(this_.currentTime);
	});

	// どの注文はいつ発生し、商品はいつ用意され、いつ処理し終わったか
	this.orderTime = (new Array(this.numOfOrder)).fill(0);
	this.removedTime = (new Array(this.numOfOrder)).fill(INF);
	this.completedTime = (new Array(this.numOfOrder)).fill(INF);

	// どの時間にどの頂点が何色であるべきか計算
	const maxTime = this.inputBlock.length;
	this.orderToVertex = new Array();
	this.vertexColor = Array.from(new Array(maxTime), () => new Array(this.V).fill(0));

	// 得点計算
	this.score = (new Array(this.T + 1)).fill(0);
	this.scoreDelta = (new Array(this.T + 1)).fill(0);
	
	let cntNewOrder = (new Array(this.V)).fill(0);	
	for(let i=0; i<maxTime; i++) {
	    if(i > 0) {
		for(let j=0; j<this.V; j++) this.vertexColor[i][j] = this.vertexColor[i-1][j];
		this.score[i] = this.score[i-1];
	    }
		
	    this.inputBlock[i][0].forEach(function(order) {
		const [id, vertex, orderTime] = order;
		this_.orderToVertex.push(vertex);
		this_.vertexColor[i][vertex - 1] = ++cntNewOrder[vertex - 1];
		this_.orderTime[id - 1] = i;
	    });

	    this.inputBlock[i][1].forEach(function(order) {
		const vertex = this_.orderToVertex[order - 1];
		this_.vertexColor[i][vertex - 1] = --cntNewOrder[vertex - 1];
		this_.completedTime[order - 1] = i;

		const waitingTime = this_.completedTime[order - 1] - this_.orderTime[order - 1];
		this_.scoreDelta[i] += this_.T * this_.T - waitingTime * waitingTime;
	    });

	    this.inputBlock[i][2].forEach(function(order) {
		this_.removedTime[order - 1] = i;
	    });

	    this.score[i] += this.scoreDelta[i];
	}

	// 各注文の状態を表すセルを作る
	this.orderStateWindow = document.getElementById('order-state-window');
	let orderStateWindowHTML = '', numOfCol = 25;
	let numOfRow = Math.ceil(this.numOfOrder / numOfCol);
	orderStateWindowHTML += '<table>';
	for(let i=0; i<numOfRow; i++) {
	    orderStateWindowHTML += '<tr>';
	    for(let j=0; j<numOfCol; j++) {
		let k = i * numOfCol + j;
		orderStateWindowHTML += '<td class="order-state-cell", id="order-state-cell-id-' + k + '">&nbsp;</td>';
	    }
	    orderStateWindowHTML += '</tr>';
	}
	orderStateWindowHTML += '</table>';
	this.orderStateWindow.innerHTML = orderStateWindowHTML;
    };

    Visualizer.prototype.calculateCarPosition = function() {
	let carPosition = [];
	let orderState = (new Array(this.numOfOrder)).fill(0);
	let orderPosition = (new Array(this.numOfOrder)).fill(-1);
	
	let u = DEPOT_INDEX, v = DEPOT_INDEX, ratio = 0, dist = 0;
	for(let i=0; i<this.outputBlock.length; i++) {
	    const p = this.outputBlock[i];

	    // STAY
	    if(p < 0) {
		carPosition.push([u, v, ratio]);
	    }
	    // MOVE
	    else {
		// 辺上での移動
		if(ratio > 0.0) {
		    // u にいるときに "MOVE u" はダメ
		    if(u === v || (u !== p && v !== p)) {
			this.outputParser.sendError('MOVE ' + p + ' is not allowed', i+1);
		    }
			
		    const edgeLength = this.edgeCostOracle[ [u, v] ];
		    dist += (u === p ? -1 : +1);
		    if(dist === 0) {
			v = u;
		    }
		    if(dist === edgeLength) {
			u = v;
			dist = 0;
		    }
		    ratio = 1.0 * dist / edgeLength;
		}
		// 頂点上での移動
		else {
		    if(!([u, p] in this.edgeCostOracle)) {
			this.outputParser.sendError('MOVE ' + p + ' is not allowed', i+1);
		    }
		    
		    const edgeLength = this.edgeCostOracle[ [u, p] ];
		    if(edgeLength === 1) {
			u = p, v = p, dist = 0;
		    }
		    else {
			v = p; dist = 1;
		    }
		    ratio = 1.0 * dist / edgeLength;
		}
		carPosition.push([u, v, ratio]);
	    }

	    // その時間に発生した注文
	    this.inputBlock[i][0].forEach(function(order) {
		const id = order[0], vertex = order[1];
		orderState[id - 1] = 1;
		orderPosition[id - 1] = vertex;
	    });

	    // その時間に商品を用意した注文
	    if(u === v && u === 1) {
		for(let k=0; k<this.numOfOrder; k++) {
		    if(orderState[k] !== 1) continue;
		    this.inputBlock[i][2].push(k+1);
		    orderState[k] = 2;
		}
	    }

	    // その時間に配達を終えた注文
	    if(u === v) {
		for(let k=0; k<this.numOfOrder; k++) {
		    if(orderPosition[k] !== u || orderState[k] !== 2) continue;
		    this.inputBlock[i][1].push(k+1);
		    orderState[k] = 3;
		}
	    }
	}
	
	return carPosition;
    };

    Visualizer.prototype.drawCar = function(time) {
	const [u, v, ratio] = this.carPosition[time];
	
	const h = 18, w = 30;
	let coordinates = this.network.getPositions([u, v]);
	
	let uc = this.network.canvasToDOM({x: coordinates[u].x, y: coordinates[u].y});
	let vc = this.network.canvasToDOM({x: coordinates[v].x, y: coordinates[v].y});
	
	let x = (uc.x + (vc.x - uc.x) * ratio - h / 2);
	let y = (uc.y + (vc.y - uc.y) * ratio - w / 2);
	
	let layerElement = document.getElementById('overlay-field');

	const canvasElement = document.getElementById('graph-field');
	const canvasWidth = canvasElement.clientWidth;
	const canvasHeight = canvasElement.clientHeight;

	const canvasRect = canvasElement.getBoundingClientRect();
	const [canvasY, canvasX] = [canvasRect.top, canvasRect.left];

	const [clx, cly] = [canvasX, canvasY];
	const [crx, cry] = [canvasX + canvasWidth, canvasY + canvasHeight];
	const [llx, lly] = [x + canvasX, y + canvasY];
	const [lrx, lry] = [llx + w, lly + h];

	if(clx <= llx && lrx <= crx && cly <= lly && lry <= cry) {
	    layerElement.style.display = 'block';
	    layerElement.style.left = '' + x + 'px';
	    layerElement.style.top  = '' + y + 'px';
	}
	else {
	    layerElement.style.display = 'none';
	}
    };

    Visualizer.prototype.changeVertexColor = function(time) {
	const NodeOption = function(num) {
	    const maxOrderNum = 10;
	    num = clamp(num, 0, maxOrderNum);
	    const h = (1.0 - 1.0 * num / maxOrderNum) * 100;
	    const hsl = 'hsl(' + h + ', 100%, 75%)';

	    const optionObj = {
		color: {
		    background: hsl,
		},
	    };
	    return optionObj;
	};

	for(let i=1; i<=this.V; i++) {
	    let node = this.network.body.nodes[i];
	    node.setOptions(NodeOption(this.vertexColor[time][i-1]));
	}
	
	this.network.redraw();
    };

    Visualizer.prototype.changeOrderStateCell = function(time) {
	const maxWaitingTime = 2500;
	const hMin = 0, hMax = 120;

	for(let i=0; i<this.numOfOrder; i++) {
	    let hsl = '', html = '&nbsp;';
	    if(time < this.orderTime[i]) {
		hsl = 'hsl(0, 0%, 75%)';
	    }
	    else if(this.orderTime[i] <= time && time < this.removedTime[i]) {
		hsl = 'hsl(0, 0%, 40%)';
	    }
	    else if(this.removedTime[i] <= time && time < this.completedTime[i]) {
		hsl = 'hsl(240, 100%, 75%)';
	    }
	    else {
		let waitingTime = this.completedTime[i] - this.orderTime[i];		
		html = '' + waitingTime;
		
		let clampWaitingTime = clamp(waitingTime, 0, maxWaitingTime);
		const h = (1.0 - 1.0 * clampWaitingTime / maxWaitingTime) * (hMax - hMin) + hMin;
		hsl = 'hsl(' + h + ', 100%, 75%)';
	    }

	    const cellId = 'order-state-cell-id-' + i;
	    let cellElement = document.getElementById(cellId);
	    cellElement.style.backgroundColor = hsl;
	    cellElement.innerHTML = html;
	}
    };

    Visualizer.prototype.changeScore = function(time) {
	let scoreDeltaWindow = document.getElementById('score-delta-window');
	let scoreSumWindow = document.getElementById('score-sum-window');
	scoreDeltaWindow.value = this.scoreDelta[time];
	scoreSumWindow.value = this.score[time];
    };
    
    Visualizer.prototype.modifyTime = function(time) {
	this.currentTime = time;
	this.drawCar(time);
	this.changeVertexColor(time);
	this.changeOrderStateCell(time);
	this.changeScore(time);
    };

    return Visualizer;
}());

let Logger = (function() {
    const Logger = function() {
	this.logWindow = document.getElementById('log-window');
    };
    Logger.prototype.changeLogMsg = function(inputLineBlock, currentTime) {
	let html = '';

	const completedOrderList = inputLineBlock[1];
	if(completedOrderList.length > 0) {
	    html += '<h3>Achieved Order (time = ' + currentTime + ')</h3>';
	    html += '<ul>';
	    for(let i=0; i<completedOrderList.length; i++) {
		html += '<li>';
		const infoStr = 'Order ID: ' + completedOrderList[i];
		html += infoStr;
		html += '</li>';
	    }
	    html += '</ul>';
	}
	
	const newOrderList = inputLineBlock[0];
	if(newOrderList.length > 0) {
	    html += '<h3>New Order (time = ' + currentTime + ')</h3>';
	    html += '<ul>';
	    for(let i=0; i<newOrderList.length; i++) {
		html += '<li>';
		const infoStr = 'Order ID: ' + newOrderList[i][0] + ', Vertex: ' + newOrderList[i][1];
		html += infoStr;
		html += '</li>';
	    }
	    html += '</ul>';
	}
	
	const removedOrderList = inputLineBlock[2];
	if(removedOrderList.length > 0) {
	    html += '<h3>Put Order (time = ' + currentTime + ')</h3>';
	    html += '<ul>';
	    for(let i=0; i<removedOrderList.length; i++) {
		html += '<li>';
		const infoStr = 'Order ID: ' + removedOrderList[i];
		html += infoStr;
		html += '</li>';
	    }
	    html += '</ul>';
	}

	this.logWindow.innerHTML = html;
    };
    return Logger;
}());

let Application = (function() {
    const Application = function() {
	const this_ = this;
	this.fileManager = new FileManager();
	this.userInterface = new UserInterface();
	
	this.fileManager.callback = function(outputData, inputData) {
	    this_.userInterface.discardPrevSession();
	    this_.userInterface.visualizer = new Visualizer(outputData, inputData);
	    this_.userInterface.init();
	};
    };    
    return Application;
}());

window.onload = function() {
    let app = new Application();
};
