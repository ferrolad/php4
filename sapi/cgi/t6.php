<?
  $a = 1;
  switch($$a-($a>0?$b[0]:$b[$$$a-1]))
  {
  	case 1:
  	  switch($a*2)
  	  {
  	  	case 1:
  	  	  $a = ($a == 4?$a:6);
  	  	  break;
  	  }
  	  $a++;
  	  break;
  	case 2:
  	  if ($a-$b>$c-1) $b = 9;
  	  else if ($b == 0) $b = 11;
  	  else
  	  {
  	  	$b = 2;
  	  	break;
  	  }
  	  $a--;
  	  break;
  	case ($a == 3? $a+10:11):
  	  $a++;
  	  $a = ($i == 0?1:2);
  	case 4:
  	  for ($i = 0; $i < 9; $i ++)
  	  {
  	  	switch($i%2)
  	  	{
  	  		case $a:
  	  		  $i+=9;
  	  		  break;
  	  		case $a+1:
  	  		  while($i<1000) $i++;
  	  		  $i = 0;
  	    }
  	    if ($i == 8)
  	    {
  	    	$i = 7;
  	    }
  	    else if ($i == 9 or $i++ > 100)
  	    {
  	    	break;
  	    }
  	    else
  	    {
  	    	continue;
  	    }
  	  }
  	  $a+=3;
  	  continue;
  	  break;
	default:
	  $a = 10;
	  break;
  }
  
  echo $a;
?>
