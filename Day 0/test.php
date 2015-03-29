<?php
$variables = [ 1, 2, 123.23, "Divjot" ];
#print_r($variables);

# Comments : Contructs :
if($variables[0] == 1) {
#  echo "Yes it is 1 \n";
} else {
 # echo "not one. \n";
}

switch($variables[3]) {
case "Divjot" : 
#  echo "3rd index has divjot \n";
  break;
case "Ravjot" :
  echo "3rd index has ravjot \n";
  break;
}

# Loop :
for($i = 0; $i < count($variables); $i++) {
# echo $variables[$i] . " \n"; # concatenate using .
}

# Foreach Loop :
foreach($variables as $v) {
#  echo $v . "\n";
}

# Foreach Loop with index
foreach($variables as $index => $value) { 
 # echo "\$variables[ $index ] = $value \n";
}

# Associative arrays
$arrayWithKeys = [
  "name" => "Praneet",
  "age" => 20,
  "salary" => 20.32434
];

foreach($arrayWithKeys as $key => $value) {
 # echo "\$arrayWithKeys[ $key ] = $value \n";
}

# Functions

function printStars($howMany = 5) {
  foreach(range(0, $howMany - 1) as $s) {
    echo "*";
  }
  echo "\n";
}

#printStars();

array_push($variables, "Hello");
$variables[] = "Newly pushed value"; # This one is faster!
print_r($variables);

print_r(implode("#", explode(" ", "This string has a lot of words.")));























?>
