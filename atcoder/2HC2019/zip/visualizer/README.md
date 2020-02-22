# Hitachi Hokudai Labo & Hokkaido University Contest 2019-1 ビジュアライザ

* これは、Hitachi Hokudai Labo & Hokkaido University Contest 2019-1 で使われるビジュアライザの説明になります。本ビジュアライザはコンテストサイトに掲載してあるビジュアライザと同一のものになります。
* 本プログラムの使用は自己責任でお願いいたします。これらのプログラムを使用することで発生したあらゆる損害に関して、北海道大学と日立製作所は補償いたしません。

## サンプルプログラムの概要
ビジュアライザは JavaScript で書かれております。

**A 問題用のビジュアライザと B 問題用のビジュアライザでは使い方が異なります。**

`./A` と `./B` にそれぞれ `index.html` がありますので、ブラウザで開いて使用してください。

## A 問題について

A 問題のビジュアライザを動かすのに必要なファイルは以下の 2 つです。これは各自で準備する必要があります。

- `testcase.in`: 問題の入力ファイルです。配布した A 問題用の `generator.cpp` を使用して作成することもできます。
- `result.out`: `testcase.in` に対する出力ファイルです。

これら 2 つのファイルを WEB ブラウザ上で読みこめば、ビジュアライザが作動します。(`testcase.in` は **Input** 欄から、`result.out` は **Output** 欄から読み込みます)

- 例として、`./A/sample` 内に `sample.in` と `sample.out` を用意しています。これらを使うと、ビジュアライザの動作が確認できます。

## B 問題について

B 問題のビジュアライザを動かすのに必要なファイルは以下の 2 つです。
- `contestant.out`
- `judge.out`

これらのファイルは、配布した B 問題用の `interactive.py` を実行して作成することができます。(詳しくは B 問題の `README.md` を参照してください)
これら 2 つのファイルを WEB ブラウザ上で読みこめば、ビジュアライザが作動します。(`contestant.out` は **Contestant Output** 欄から、`judge.out` は **Judge Output** 欄から読み込みます)

- 例として、`./B/sample` 内に `contestant.out` と `judge.out` を用意しています。これらを使うと、ビジュアライザの動作が確認できます。
