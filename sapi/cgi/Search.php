<?
/***********************************************************************/
/*                                                                     */
/*  FILE        :Search.php                                            */
/*  DATE        :2005/07/14                                            */
/*  DESCRIPTION :用户界面层/门店资料管理/搜索                        　*/
/*  PROJECT     :数字租赁系统                                          */
/*                                                                     */
/***********************************************************************/


if (!isset($REALROOTPATH)) $REALROOTPATH = substr(dirname($HTTP_SERVER_VARS['SCRIPT_FILENAME']).'/', 0, -strlen('/ui/shop')-1);
if (!isset($ROOTPATH)) $ROOTPATH = substr(dirname($HTTP_SERVER_VARS['PHP_SELF']).'/',0,-strlen('/ui/Shop')-1);
require_once $REALROOTPATH . '/ui/ui_common.php';
require_once $REALROOTPATH . '/bl/SessionCenter.php';
require_once $REALROOTPATH . '/bl/LogControl.php';
require_once $REALROOTPATH . '/en/BOD/Shop.php';
require_once $REALROOTPATH . '/en/BOD/SaleAgent.php';


if (!$g_SessionCenter->Check (0x000B0000))				/* 检查会话状态及是否有门店资料管理权限 */
{														/* 无权 */
	ExitError("拒绝访问");
}
?>
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=gb2312">
<title>门店资料搜索</title>
<style type="text/css">
<!--
<!--
.text {
	font: 9pt/12pt "宋体";
	text-transform: none;
	color: #000000;
	text-decoration: none;
}
-->
-->
</style>
<script src="../js/common.js"></script>
<script src="../js/Calendar30.js"></script>
<script>
function NewWindow(url, name)
{
	window.open(url, name, 'height=560, top=50, left=200, width=550,resizable=no, scrollbars=yes');
}

function DelItem()
{
	obj = form1.item_sel;

	if (CheckNum(obj)==0)
	{
		alert('请在列表选中要删除的项');
	}
	else
	{
		if (confirm('您确定要删除选中的门店吗？'))
		{
			window.open("Del.php?id="+ArrEle(obj,FirstCheck(obj)).value, 'window_null');
		}
	}
}

function EditItem()
{
	obj = form1.item_sel;

	if (CheckNum(obj)==0)
	{
		alert('请在列表选中要修改的门店');
	}
	else
	{
		NewWindow("EditPrep.php?id="+ArrEle(obj,FirstCheck(obj)).value, 'Shop_edit');
	}
}

function StopResumeItem()
{
	obj = form1.item_sel;	

	if (CheckNum(obj)==0)
	{
		alert('请在列表选中要停止或恢复的门店');
	}
	else
	{
		NewWindow("StopResumePrep.php?id="+ArrEle(obj,FirstCheck(obj)).value, 'Shop_edit');
	}
}

function PresentItem()
{
	obj = form1.item_sel;	

	if (CheckNum(obj)==0)
	{
		alert('请在列表选中要赠点的门店');
	}
	else
	{
		NewWindow("PresentEditPrep.php?id="+ArrEle(obj,FirstCheck(obj)).value, 'Shop_edit');
	}
}

function PackageItem()
{
	obj = form1.item_sel;	

	if (CheckNum(obj)==0)
	{
		alert('请在列表选中一个门店');
	}
	else
	{
		NewWindow("PackageList.php?id="+ArrEle(obj,FirstCheck(obj)).value, 'Shop_edit');
	}
}

function PlayFeeItem()
{
	obj = form1.item_sel;	

	if (CheckNum(obj)==0)
	{
		alert('请在列表选中一个门店');
	}
	else
	{
		NewWindow("PlayFeeEditPrep.php?id="+ArrEle(obj,FirstCheck(obj)).value, 'Shop_edit');
	}
}

function MemberGradeItem()
{
	obj = form1.item_sel;	

	if (CheckNum(obj)==0)
	{
		alert('请在列表选中一个门店');
	}
	else
	{
		NewWindow("MemberGradeEditPrep.php?id="+ArrEle(obj,FirstCheck(obj)).value, 'Shop_edit');
	}
}

function MemberBelongItem()
{
	NewWindow("MemberBelongPrep.php", 'Shop_edit');
}

function orderby(a)
{
	if (a == form1.orderby.value)
	{
		if (form1.asc.value == 0)
		{
			form1.asc.value = 1;
		}
		else
		{
			form1.asc.value = 0;
		}
	}
	else
	{
		form1.asc.value = 1;				/* 升序 */
		form1.orderby.value = a;
	}
	
	form1.submit();
}
</script>
</head>

<body bgcolor="#F7F7F7" link="#000000" vlink="#99CC33" alink="#000000" leftmargin="0" topmargin="0" marginwidth="0" marginheight="0">
<table width="817"  border="0" align="left" cellpadding="0" cellspacing="0">
  <!--DWLayoutTable-->
  <tr> 
    <td width="268" height="124" align="right" valign="middle"> 
      <p align="left"><img src="../img/Shop.jpg" width="264" height="48">　　　</p></td>
    <td align="right" valign="bottom" nowrap> 
      <div align="right" class="text"> 
        [<a href="javascript:NewWindow('AddPrep.php', 'shop_add');" class="text">添加</a> 
        | <a href="javascript:DelItem();" class="text">删除 </a>| <a href="javascript:EditItem();" class="text">修改</a> 
        | <a href="javascript:MemberGradeItem();" class="text">会员等级</a> | <a href="javascript:PlayFeeItem();" class="text">点播费 
        </a>| <a href="javascript:PackageItem();" class="text">产品包 </a>| <a href="javascript:PresentItem();" class="text">赠点</a> 
        | <a href="javascript:MemberBelongItem();" class="text">会员所属 </a>| <a href="javascript:StopResumeItem();" class="text"> 
        冻结/恢复]</div></td>
  </tr>
  <tr> 
    <td  colspan="2" valign="top" align="right">
        <form name="form1" method="post" action="">
          <hr>
		  <input name="orderby" type="hidden", value="<? echo $orderby?>">
                <input name="asc" type="hidden", value="<? echo $asc?>">
          <table  border="0" cellpadding="0" cellspacing="0">
            <tr class="text"> 
              <td   nowrap> 
                <div align="right">　门店名称:</div></td>
              <td   nowrap> 
                <div align="left"> 
                  <input type="text" name="name" value="<? echo $name; ?>" size="12">
                </div></td>
              <td   nowrap> 
                <div align="right">　国家:</div></td>
              <td   nowrap> 
                <div align="left"> 
                  <input type="text" name="country" value="<? echo $country; ?>" size="12">
                </div></td>
              <td  nowrap> 
                <div align="right">　联系人:</div></td>
              <td   nowrap> 
                <div align="left"> 
                  <input type="text" name="contact" value="<? echo $contact; ?>" size="12">
                </div></td>
              <td   nowrap> 
                <div align="right">　所属代理商: </div></td>
              <td width="38"  align="right" nowrap> <div align="left"> 
                  <select name="sa_id">
                    <?
/*-- 搜索销售代理商资料 begin --*/
$SaleAgent_set	= new CSaleAgentSet();
if ($g_SessionCenter->usertype == 2)		/* 发行商 */
{
	echo "            <option value=\"-1\" style=\"background-color:#CCCCCC\" selected>所有销售代理商</option>\n";
	$SaleAgent_set->Search ($SaleAgents, "", "", FALSE, 0, "");
	if ($SaleAgent_id == '') $SaleAgent_id = -1;
}
else if ($g_SessionCenter->usertype == 3)	/* 销售代理商 */
{
	$SaleAgents[0]			= new CSaleAgent();
	$SaleAgents[0]->id		= $g_SessionCenter->subjectid;
	$SaleAgents[0]->name	= $g_SessionCenter->subjectname;
	
	if ($SaleAgent_id == '') 
	{
		$SaleAgent_id = $g_SessionCenter->subjectid;
	
   }
}


/*-- 搜索销售代理商资料: end --*/

/*-- 列出销售代理商: begin --*/
$n    = count($SaleAgents);
for ($i = 0; $i < $n; $i++)
{
	if ($SaleAgents[$i]->id == $SaleAgent_id)
	{
		echo "            <option value=".$SaleAgents[$i]->id." selected>".$SaleAgents[$i]->name."</option>\n";
	}
	else
	{
		echo "            <option value=".$SaleAgents[$i]->id.">".$SaleAgents[$i]->name."</option>\n";
	}
}
/*-- 列出销售代理商: end --*/
?>
                  </select>
                </div>
                <div align="right"> </div></td>
              <td  align="right" nowrap>　状态:</td>
              <td  align="right" nowrap> <div align="left"> 
                  <select name="status">
                    <option value="" style="background-color:#CCCCCC" <?if($status == '') echo "selected" ;?>>所有状态</option>
                    <option value="0"<?if($status == '0') echo "selected" ;?>>活动</option>
                    <option value="1" <?if($status == '1') echo "selected" ;?>>冻结</option>
                  </select>
                </div></td>
              <td  align="right" nowrap>
<input type="submit" name="Submit" value="查询"></td>
            </tr>
            <tr class="text"> 
              <td nowrap> 
                <div align="right">　省份/州:</div></td>
              <td nowrap> <div align="left"> 
                  <input type="text" name="prov" value="<? echo $prov; ?>" size="12">
                </div></td>
              <td nowrap> <div align="right">　城市:</div></td>
              <td nowrap> <div align="left"> 
                  <input type="text" name="city" value="<?echo $city;?>" size="12">
                </div></td>
              <td nowrap> <div align="right">　登录名:</div></td>
              <td nowrap> <div align="left"> 
                  <input type="text" name="userid" value="<? echo $userid; ?>" size="12">
                </div></td>
              <td nowrap> <div align="right" class="text">创建日期:</div></td>
              <td colspan="4"  nowrap> <div align="left"> 
                  <input name="create_date_begin" type="text" onFocus="calendar();" value="<? echo $create_date_begin; ?>" size="13" readonly>
                  <span class="text">~</span> <span class="text"> 
                  <input name="create_date_end" type="text" onFocus="calendar();" value="<? echo $create_date_end; ?>" size="13" readonly>
                  </span></div>
                <div align="right"> </div></td>
            </tr>
          </table>
          <table width="100%"  border="1" cellpadding="0" cellspacing="0">
            <tr class="text"  align="center" bgcolor="#CCCCCC"> 
              <td nowrap> 
                <div align="center"><font color="#993300">选择</font></div></td>
              <td nowrap> 
                <div align="center"><a href="javascript:orderby('name');" class="text"><font color="#993300">门店名称<?if ($orderby == 'name'){echo ($asc?'↑':'↓');}?></font></a></div></td>
              <td nowrap> 
                <div align="center"><a href="javascript:orderby('contact');" class="text"><font color="#993300">联系人<?if ($orderby == 'contact'){echo ($asc?'↑':'↓');}?></font></a></div></td>
              <td nowrap> 
                <div align="center"><a href="javascript:orderby('userid');" class="text"><font color="#993300">登录名<?if ($orderby == 'userid'){echo ($asc?'↑':'↓');}?></font></a></div></td>
              <td nowrap> 
                <div align="center"><a href="javascript:orderby('sa_name');" class="text"><font color="#993300">所属代理商<?if ($orderby == 'sa_name'){echo ($asc?'↑':'↓');}?></font></a></div></td>
              <td nowrap> 
                <div align="center"><a href="javascript:orderby('status');" class="text"><font color="#993300">状态<?if ($orderby == 'status'){echo ($asc?'↑':'↓');}?></font></a></div></td>
              <td nowrap> 
                <div align="center"><font color="#993300">备注</font></div></td>
            </tr>
<?
if ($g_SessionCenter->usertype == 3)				/* 销售代理商 */
{
	if ($sa_id == '')
	{
		$sa_id = $g_SessionCenter->subjectid;
	}
	
	if ($g_SessionCenter->subjectid != $sa_id)		/* 查询的不是属于本销售代理商的门店 */
	{
		ExitError ("禁止访问");
	}
}

/*-- 生成搜索条件: begin --*/
$terms = array();

$j = 0;

if (($name !== NULL) and ($name !== ""))			/* 门店名称 */
{
	$terms[$j++]	= array('name', $name,'',  4);
}

if (($contact !== NULL) and ($contact !== ""))		/* 联系人 */
{
	$terms[$j++]	= array('contact', $contact,'',  4);
}

if (($userid !== NULL) and ($userid !== ""))		/* 登录名 */
{
	$terms[$j++]	= array('userid', $userid, '', 4);
}
if (($country!== NULL) and ($country !== ""))		/* 国家 */
{
	$terms[$j++]	= array('country', $country,'',  4);
}
if (($prov!== NULL) and ($prov !== ""))			/* 省份/州*/
{
	$terms[$j++]	= array('prov', $prov, '', 4);
}
if (($city !== NULL) and ($city !== ""))		/* 城市*/
{
	$terms[$j++]	= array('city', $city, '', 4);
}
if (($sa_id !== NULL) and ($sa_id !== ""))		/* 销售代理商编号 */
{
	$terms[$j++]	= array('sa_id', $sa_id, $sa_id,  1);
}
if (($status!== NULL) and ($status !== ""))		/* 状态*/
{
	$terms[$j++]	= array('status', $status,$status,  1);
}
if (($create_date_begin != NULL) or ($create_date_end != NULL))		/* 出品日期 */
{
	$terms[$j++]	= array('create_date', ($create_date_begin==''?NULL:$create_date_begin), ($create_date_end==''?NULL:$create_date_end), 1);
}
/*-- 生成搜索条件: end --*/

if ($page == NULL)
{
	$page = 1;
}
/*-- 搜索门店资料: begin --*/
$Shop_set	= new CShopSet();
$total = $Shop_set->Search ($Shops, $terms, $orderby, $asc, ($page-1)*$g_PageSize, $g_PageSize);
$n	 		= count($Shops);

/*-- 搜索门店资料: end --*/
/********* for debug
$n = 20;
$total = 500;
*********/
/*-- 添加日志: begin --*/
Log_Add(
	'门店信息',						/* 操作对象类型名 */
	'',								/* 操作对象名称 */
	5,								/* 操作动作（1. 添加, 2. 删除, 3. 修改, 4. 查看, 5. 搜索, 6. 其它） */
	($total >= 0 ? 0 : 1),			/* 操作结果（0. 成功, 非0. 失败） */
	''								/* 备注 */
);
/*-- 添加日志: end --*/
$max_page = (int)(($total+$g_PageSize-1)/$g_PageSize);

/*-- 列出门店资料: begin --*/
for($i = 0; $i <$n; $i++)
{

?>
                  <tr align="center" bgcolor="<? if (($i%2) == 0) echo "#F7F7F7"; else echo "#FFFFFF"; ?>" class="text"> 
                    
              <td height="20" nowrap> 
                <input type="radio" name="item_sel" value="<? echo $Shops[$i]->id; ?> "> 
                    </td>
                    
              <td nowrap><? echo $Shops[$i]->name; ?>&nbsp;</td>
                    
              <td nowrap><? echo $Shops[$i]->contact; ?>&nbsp;</td>
                    
              <td nowrap><? echo $Shops[$i]->userid; ?>&nbsp;</td>
                    
              <td nowrap><? echo $Shops[$i]->sa_name; ?>&nbsp;</td>
                    
              <td nowrap> 
                <?
                    if($Shops[$i]->status == 0) 
                    {
                        echo "活动";
                    }
                    else
                    {
                    	echo "冻结";
                    }
                    
/*-- 列出门店资料: end --*/                    ?>
                &nbsp; </td>
                    
              <td nowrap><? echo $Shops[$i]->notes; ?>&nbsp;</td>
                  </tr>
<?
}
?>
                  <tr align="center" bgcolor="#CCCCCC" class="text"> 
                    
              <td height="26" colspan="7" nowrap> 第<font color="#FF0000"><? echo $page; ?></font>页　 
                <a href="javascript:form1.page.value=1; form1.submit();" class="text">首页　</a> 
                <?
if ($page > 1)			/* 不是首页 */
{
?>
                <a href="javascript:form1.page.value=<? echo $page-1; ?>; form1.submit();" class="text">上一页　</a> 
                <?
}
?>
                <?
if ($page < $max_page)	/* 不是末页 */
{
?>
                <a href="javascript:form1.page.value=<? echo $page+1; ?>; form1.submit();" class="text">下一页　</a> 
                <?
}
?>
                <a href="javascript:form1.page.value=<? echo $max_page; ?>; form1.submit();" class="text">未页　</a> 
                　 <span class="text"> 共<? echo $max_page ?>页　 转到第 
                <input name="page" type="text" size="3" value="<? echo $page;?>">页 
                      </span>
         </td>
              </tr>    
          </table>
          </form>
</td>
  </tr>
</table>
</body>
</html>
<?
/************************************************
 * @ Search.php v1.0 log @
 *
 * Revision 1.0.0.0     RD031     2005/07/14
 * create file
 * 
 ***********************************************/
?>