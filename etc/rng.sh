#!/bin/sh
echo `ruby -e "puts (0..499).to_a.shuffle.join(' ')"` > rn
