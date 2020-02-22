#!/usr/bin/perl

    print( "usage: ec", "ho <plaintext|", "ciphertext> | $0 <key>" ) && exit
      unless scalar @ARGV;
    $/ = \1;
    use constant H => 128;
    @key = split "", $ARGV[0];
    for ( @a = [], $i = H ; $i-- ; $a[$i] = $i ) { }
    for ( $j = $i = 0 ; $i < H ; $i++ ) {
        $j += $a[$i] + ord $key[ $i % 16 ];
        ( $a[$i], $a[ $j % H ] ) = ( $a[ $j % H ], $a[$i] );
    }
    for ( $i = $j = $m = 0 ; <STDIN> ; print chr( ord $_ ^ $l ^ $m ) ) {
        $j += $a[ ++$i % H ];
        ( $a[ $i % H ], $a[ $j % H ] ) = ( $a[ $j % H ], $a[ $i % H ] );
        $l = $a[ ( $a[ $i % H ] + $a[ $j % H ] ) % H ];
        $m =
          ( ord( $key[ $i / 64 % 16 ] ) << $i ) & 0xff;
    }    # -- Alok
