<?
  include_once "a.php";

  class C1
  {
  	var $v1 = 10;
  	var $v2;
  	
  	function C1()
  	{
  		$this->v1 = 0;
  		$this->v2 = 1;
  	}
  	
  	function GetV()
  	{
  		return $this->v1 + $this->v2;
  	}
  	
  	function SetV($v1, $v2)
  	{
  		$this->v1 = $v1;
  		$this->v2 = $v2;
  	}
  	
  	function calc($v3)
  	{
  		$aa = GetV();
  		$aa += count($v3);
  		
  		SetV($v3,$aa);
  		
  		return $aa;
  	}
  }
  
  class C2 extends C1
  {
  	var $v2 = 3;
  	var $v3 = 'abc';
  	var $v4 = 1;
  	
  	function GetV3()
  	{
  		return $this->v3;
  	}
  	
  	function GetV()
  	{
  		return C1::GetV() + $this->v3 + $this->v4;
  	}
  }

	function f5(const $d)
	{
		$a = $test+4;
		
		$ccc= new C1();
		
		$ccc1 = $ccc->GetV();
		
		$d++;
		
		$a += $d *5;
		
		return 3;
	}
	
  function myfunc2($p1)
  {
  	$p[0] = $p1-3;
  	
  	$p1 = $p[0]>>3;
  	
  	$dd = 3;
  	
  	f5(&$dd);
  	
  	return $dd;
  }
  
  function myfunc($p1, $p2 = 'default', $hee = 2)
  {
  	$p2 = "ok:".$p1;
  	return $p2;
  }
  
  $a = count($form1);
//  $a = $func1(1,2);
  $a = myfunc2(&$b);
  
  if($a <9)
  {
	  function f4()
	  {
	  	echo "lll";
	  }
	  
	  $a++;
  }

  $b = myfunc2(1);
  
  echo $b;
?>
