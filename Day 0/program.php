<?php

$names = array_slice(explode("\n", file_get_contents('names.txt')), 0, -1);
$peopleIKnow = array_slice(explode("\n", file_get_contents('peopleiknow.txt')), 0, -1);

foreach($names as $n) { echo "I " . (in_array($n, $peopleIKnow)? "do" : "don't") . " know $n\n\n"; }

printf("I have %0.2f %% knowledge of people around me.\n", (count(array_diff($names, $peopleIKnow)) - count($peopleIKnow))/count($names)*100);
