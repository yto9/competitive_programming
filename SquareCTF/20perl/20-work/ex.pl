#!/usr/bin/perl

use constant H => 128;
@key = split "", $ARGV[0];
for ( @a = [], $i = H ; $i-- ; $a[$i] = $i ) { }
for ( $j = $i = 0 ; $i < H ; $i++ ) {
    $j += $a[$i] + ord $key[ $i % 16 ];
    ( $a[$i], $a[ $j % H ] ) = ( $a[ $j % H ], $a[$i] );
}
