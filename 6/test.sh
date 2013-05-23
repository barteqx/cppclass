#!/bin/bash
echo "Sorting on a vector using copying:"
time ./vsc
echo
echo "Sorting on a vector using std::move:"
time ./vsm
echo
echo "Sorting on a list using copying:"
time ./lsc
echo
echo "Sorting on a list using std::move:"
time ./lsm
