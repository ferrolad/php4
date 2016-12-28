<?
  $g = __LINE__;

  	while ($a < 10)
  	{
  	  $a++;
	  declare (ticks = 2)
	  {
  		while ($b == 0)
  		{
		  	$a++;
		  	$b = ($a > 10 ? $a+1 : $a-1);
		  	$c[1] = $a;
		 }
	  }
    }
    
  $info = `ls`;
  declare (ticks = 1)
  {
	  $info = shell_exec('ls');
	  $a = sin(4);
  }
  $c = cos(1);
  declare (ticks = 4)
  {
  	$b = sin(1);
  }
  
  $info = array('coffee', 'tea', 'water');
  
  list($a, list($b, $c)) = $info;
  

  echo $a;
?>
