#!/usr/bin/bash

# btc runs 
./model -data btcbusdcomplete_iso.csv -out btc_buyhold.csv -strategy buyhold > btc_buyhold.log
./model -data btcbusdcomplete_iso.csv -out btc_ema20.csv -strategy ema20 > btc_ema20.log
./model -data btcbusdcomplete_iso.csv -out btc_ema50.csv -strategy ema50 > btc_ema50.log

# eth runs
./model -data ethbusdcomplete_iso.csv -out eth_buyhold.csv -strategy buyhold > eth_buyhold.log
./model -data ethbusdcomplete_iso.csv -out eth_ema20.csv -strategy ema20 > eth_ema20.log
./model -data ethbusdcomplete_iso.csv -out eth_ema50.csv -strategy ema50 > eth_ema50.log

# bnb runs
./model -data bnbbusdcomplete_iso.csv -out bnb_buyhold.csv -strategy buyhold > bnb_buyhold.log
./model -data bnbbusdcomplete_iso.csv -out bnb_ema20.csv -strategy ema20 > bnb_ema20.log
./model -data bnbbusdcomplete_iso.csv -out bnb_ema50.csv -strategy ema50 > bnb_ema50.log

if [ -d results ] 
then
    rm -rf results
fi
mkdir results
mv btc_* bnb_* eth_* results

