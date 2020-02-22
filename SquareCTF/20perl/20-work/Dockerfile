FROM ubuntu:18.04

RUN apt-get update && apt-get upgrade -y

RUN apt-get install -y wget && \
apt-get install -y gcc && \
apt-get install -y make && \
  wget http://www.cpan.org/src/5.0/perl-5.20.1.tar.gz && \
  tar xvfz perl-5.20.1.tar.gz && \
  cd perl-5.20.1 && \
  ./configure.gnu && \
  make && \
  make install

COPY ./20.pl ./
COPY ./flag.pdf.enc ./
