<?
  function fun_1($arg0,$arg1)
  {
    $var1 = 16;
    return "a".$arg0.$var1."b";
  }

  $i = 4;
  if ($i < 3)
  {
    echo "ng";
  }

  for ($i = 0; $i < 5; $i++)
  {
    $var2 = fun_1($i." hello: ",2);
    echo $var2;
    echo "\n";
  }
?>
