#!/bin/bash
free -m | awk 'NR==2{printf "Memory Usage: %sMB (%.2f%%)\n", $3,$2,$3*100/$2 }'
