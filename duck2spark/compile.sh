#!/bin/bash
python2 duckencoder.py -i test.duck -o test.bin -l gb
python2 duck2spark.py -i test.bin -l 1 -f 500 -o test.ino
