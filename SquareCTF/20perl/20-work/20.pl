#!/usr/bin/perl

use String::Random;

my $sr = String::Random->new();
print("usage: echo <plaintext|ciphertext> | $0 <key>") && exit
  unless scalar @ARGV;
$/ = \1;
use constant H => 128;
while(1){
  @key = split "", $sr->randregex('.{16}');
  for ( @a = [], $i = H ; $i-- ; $a[$i] = $i ) { }
  for ( $j = $i = 0 ; $i < H ; $i++ ) {
      $j += $a[$i] + ord $key[ $i % 16 ];
      ( $a[$i], $a[ $j % H ] ) = ( $a[ $j % H ], $a[$i] );
  }
  my $res = '';
  for ( $i = $j = $m = 0 ; <STDIN> ; $res.=chr(ord $_ ^ $l ^ $m) ) {
      $j += $a[ ++$i % H ];
      ( $a[ $i % H ], $a[ $j % H ] ) = ( $a[ $j % H ], $a[ $i % H ] );
      $l = $a[ ( $a[ $i % H ] + $a[ $j % H ] ) % H ];
      $m =
        ( ord( $key[ $i / 64 % 16 ] ) << $i ) & 0xff;
      if ($i >= 5) {
        last;
      }
      # print $res . "\n";
  }
  if ($res[0] eq '%' && $res[1] eq 'P' && $res[2] eq 'D' && $res[3] eq 'F' ) {
    for ($k=0; $k <16; $k++) {
      print $key[$k];
    }
    print "\n";
    last;
  }
  
      # -- Alok
}