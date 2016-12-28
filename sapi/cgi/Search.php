<?
/***********************************************************************/
/*                                                                     */
/*  FILE        :Search.php                                            */
/*  DATE        :2005/07/14                                            */
/*  DESCRIPTION :�û������/�ŵ����Ϲ���/����                        ��*/
/*  PROJECT     :��������ϵͳ                                          */
/*                                                                     */
/***********************************************************************/


if (!isset($REALROOTPATH)) $REALROOTPATH = substr(dirname($HTTP_SERVER_VARS['SCRIPT_FILENAME']).'/', 0, -strlen('/ui/shop')-1);
if (!isset($ROOTPATH)) $ROOTPATH = substr(dirname($HTTP_SERVER_VARS['PHP_SELF']).'/',0,-strlen('/ui/Shop')-1);
require_once $REALROOTPATH . '/ui/ui_common.php';
require_once $REALROOTPATH . '/bl/SessionCenter.php';
require_once $REALROOTPATH . '/bl/LogControl.php';
require_once $REALROOTPATH . '/en/BOD/Shop.php';
require_once $REALROOTPATH . '/en/BOD/SaleAgent.php';


if (!$g_SessionCenter->Check (0x000B0000))				/* ���Ự״̬���Ƿ����ŵ����Ϲ���Ȩ�� */
{														/* ��Ȩ */
	ExitError("�ܾ�����");
}
?>
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=gb2312">
<title>�ŵ���������</title>
<style type="text/css">
<!--
<!--
.text {
	font: 9pt/12pt "����";
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
		alert('�����б�ѡ��Ҫɾ������');
	}
	else
	{
		if (confirm('��ȷ��Ҫɾ��ѡ�е��ŵ���'))
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
		alert('�����б�ѡ��Ҫ�޸ĵ��ŵ�');
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
		alert('�����б�ѡ��Ҫֹͣ��ָ����ŵ�');
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
		alert('�����б�ѡ��Ҫ������ŵ�');
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
		alert('�����б�ѡ��һ���ŵ�');
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
		alert('�����б�ѡ��һ���ŵ�');
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
		alert('�����б�ѡ��һ���ŵ�');
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
		form1.asc.value = 1;				/* ���� */
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
      <p align="left"><img src="../img/Shop.jpg" width="264" height="48">������</p></td>
    <td align="right" valign="bottom" nowrap> 
      <div align="right" class="text"> 
        [<a href="javascript:NewWindow('AddPrep.php', 'shop_add');" class="text">���</a> 
        | <a href="javascript:DelItem();" class="text">ɾ�� </a>| <a href="javascript:EditItem();" class="text">�޸�</a> 
        | <a href="javascript:MemberGradeItem();" class="text">��Ա�ȼ�</a> | <a href="javascript:PlayFeeItem();" class="text">�㲥�� 
        </a>| <a href="javascript:PackageItem();" class="text">��Ʒ�� </a>| <a href="javascript:PresentItem();" class="text">����</a> 
        | <a href="javascript:MemberBelongItem();" class="text">��Ա���� </a>| <a href="javascript:StopResumeItem();" class="text"> 
        ����/�ָ�]</div></td>
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
                <div align="right">���ŵ�����:</div></td>
              <td   nowrap> 
                <div align="left"> 
                  <input type="text" name="name" value="<? echo $name; ?>" size="12">
                </div></td>
              <td   nowrap> 
                <div align="right">������:</div></td>
              <td   nowrap> 
                <div align="left"> 
                  <input type="text" name="country" value="<? echo $country; ?>" size="12">
                </div></td>
              <td  nowrap> 
                <div align="right">����ϵ��:</div></td>
              <td   nowrap> 
                <div align="left"> 
                  <input type="text" name="contact" value="<? echo $contact; ?>" size="12">
                </div></td>
              <td   nowrap> 
                <div align="right">������������: </div></td>
              <td width="38"  align="right" nowrap> <div align="left"> 
                  <select name="sa_id">
                    <?
/*-- �������۴��������� begin --*/
$SaleAgent_set	= new CSaleAgentSet();
if ($g_SessionCenter->usertype == 2)		/* ������ */
{
	echo "            <option value=\"-1\" style=\"background-color:#CCCCCC\" selected>�������۴�����</option>\n";
	$SaleAgent_set->Search ($SaleAgents, "", "", FALSE, 0, "");
	if ($SaleAgent_id == '') $SaleAgent_id = -1;
}
else if ($g_SessionCenter->usertype == 3)	/* ���۴����� */
{
	$SaleAgents[0]			= new CSaleAgent();
	$SaleAgents[0]->id		= $g_SessionCenter->subjectid;
	$SaleAgents[0]->name	= $g_SessionCenter->subjectname;
	
	if ($SaleAgent_id == '') 
	{
		$SaleAgent_id = $g_SessionCenter->subjectid;
	
   }
}


/*-- �������۴���������: end --*/

/*-- �г����۴�����: begin --*/
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
/*-- �г����۴�����: end --*/
?>
                  </select>
                </div>
                <div align="right"> </div></td>
              <td  align="right" nowrap>��״̬:</td>
              <td  align="right" nowrap> <div align="left"> 
                  <select name="status">
                    <option value="" style="background-color:#CCCCCC" <?if($status == '') echo "selected" ;?>>����״̬</option>
                    <option value="0"<?if($status == '0') echo "selected" ;?>>�</option>
                    <option value="1" <?if($status == '1') echo "selected" ;?>>����</option>
                  </select>
                </div></td>
              <td  align="right" nowrap>
<input type="submit" name="Submit" value="��ѯ"></td>
            </tr>
            <tr class="text"> 
              <td nowrap> 
                <div align="right">��ʡ��/��:</div></td>
              <td nowrap> <div align="left"> 
                  <input type="text" name="prov" value="<? echo $prov; ?>" size="12">
                </div></td>
              <td nowrap> <div align="right">������:</div></td>
              <td nowrap> <div align="left"> 
                  <input type="text" name="city" value="<?echo $city;?>" size="12">
                </div></td>
              <td nowrap> <div align="right">����¼��:</div></td>
              <td nowrap> <div align="left"> 
                  <input type="text" name="userid" value="<? echo $userid; ?>" size="12">
                </div></td>
              <td nowrap> <div align="right" class="text">��������:</div></td>
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
                <div align="center"><font color="#993300">ѡ��</font></div></td>
              <td nowrap> 
                <div align="center"><a href="javascript:orderby('name');" class="text"><font color="#993300">�ŵ�����<?if ($orderby == 'name'){echo ($asc?'��':'��');}?></font></a></div></td>
              <td nowrap> 
                <div align="center"><a href="javascript:orderby('contact');" class="text"><font color="#993300">��ϵ��<?if ($orderby == 'contact'){echo ($asc?'��':'��');}?></font></a></div></td>
              <td nowrap> 
                <div align="center"><a href="javascript:orderby('userid');" class="text"><font color="#993300">��¼��<?if ($orderby == 'userid'){echo ($asc?'��':'��');}?></font></a></div></td>
              <td nowrap> 
                <div align="center"><a href="javascript:orderby('sa_name');" class="text"><font color="#993300">����������<?if ($orderby == 'sa_name'){echo ($asc?'��':'��');}?></font></a></div></td>
              <td nowrap> 
                <div align="center"><a href="javascript:orderby('status');" class="text"><font color="#993300">״̬<?if ($orderby == 'status'){echo ($asc?'��':'��');}?></font></a></div></td>
              <td nowrap> 
                <div align="center"><font color="#993300">��ע</font></div></td>
            </tr>
<?
if ($g_SessionCenter->usertype == 3)				/* ���۴����� */
{
	if ($sa_id == '')
	{
		$sa_id = $g_SessionCenter->subjectid;
	}
	
	if ($g_SessionCenter->subjectid != $sa_id)		/* ��ѯ�Ĳ������ڱ����۴����̵��ŵ� */
	{
		ExitError ("��ֹ����");
	}
}

/*-- ������������: begin --*/
$terms = array();

$j = 0;

if (($name !== NULL) and ($name !== ""))			/* �ŵ����� */
{
	$terms[$j++]	= array('name', $name,'',  4);
}

if (($contact !== NULL) and ($contact !== ""))		/* ��ϵ�� */
{
	$terms[$j++]	= array('contact', $contact,'',  4);
}

if (($userid !== NULL) and ($userid !== ""))		/* ��¼�� */
{
	$terms[$j++]	= array('userid', $userid, '', 4);
}
if (($country!== NULL) and ($country !== ""))		/* ���� */
{
	$terms[$j++]	= array('country', $country,'',  4);
}
if (($prov!== NULL) and ($prov !== ""))			/* ʡ��/��*/
{
	$terms[$j++]	= array('prov', $prov, '', 4);
}
if (($city !== NULL) and ($city !== ""))		/* ����*/
{
	$terms[$j++]	= array('city', $city, '', 4);
}
if (($sa_id !== NULL) and ($sa_id !== ""))		/* ���۴����̱�� */
{
	$terms[$j++]	= array('sa_id', $sa_id, $sa_id,  1);
}
if (($status!== NULL) and ($status !== ""))		/* ״̬*/
{
	$terms[$j++]	= array('status', $status,$status,  1);
}
if (($create_date_begin != NULL) or ($create_date_end != NULL))		/* ��Ʒ���� */
{
	$terms[$j++]	= array('create_date', ($create_date_begin==''?NULL:$create_date_begin), ($create_date_end==''?NULL:$create_date_end), 1);
}
/*-- ������������: end --*/

if ($page == NULL)
{
	$page = 1;
}
/*-- �����ŵ�����: begin --*/
$Shop_set	= new CShopSet();
$total = $Shop_set->Search ($Shops, $terms, $orderby, $asc, ($page-1)*$g_PageSize, $g_PageSize);
$n	 		= count($Shops);

/*-- �����ŵ�����: end --*/
/********* for debug
$n = 20;
$total = 500;
*********/
/*-- �����־: begin --*/
Log_Add(
	'�ŵ���Ϣ',						/* �������������� */
	'',								/* ������������ */
	5,								/* ����������1. ���, 2. ɾ��, 3. �޸�, 4. �鿴, 5. ����, 6. ������ */
	($total >= 0 ? 0 : 1),			/* ���������0. �ɹ�, ��0. ʧ�ܣ� */
	''								/* ��ע */
);
/*-- �����־: end --*/
$max_page = (int)(($total+$g_PageSize-1)/$g_PageSize);

/*-- �г��ŵ�����: begin --*/
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
                        echo "�";
                    }
                    else
                    {
                    	echo "����";
                    }
                    
/*-- �г��ŵ�����: end --*/                    ?>
                &nbsp; </td>
                    
              <td nowrap><? echo $Shops[$i]->notes; ?>&nbsp;</td>
                  </tr>
<?
}
?>
                  <tr align="center" bgcolor="#CCCCCC" class="text"> 
                    
              <td height="26" colspan="7" nowrap> ��<font color="#FF0000"><? echo $page; ?></font>ҳ�� 
                <a href="javascript:form1.page.value=1; form1.submit();" class="text">��ҳ��</a> 
                <?
if ($page > 1)			/* ������ҳ */
{
?>
                <a href="javascript:form1.page.value=<? echo $page-1; ?>; form1.submit();" class="text">��һҳ��</a> 
                <?
}
?>
                <?
if ($page < $max_page)	/* ����ĩҳ */
{
?>
                <a href="javascript:form1.page.value=<? echo $page+1; ?>; form1.submit();" class="text">��һҳ��</a> 
                <?
}
?>
                <a href="javascript:form1.page.value=<? echo $max_page; ?>; form1.submit();" class="text">δҳ��</a> 
                �� <span class="text"> ��<? echo $max_page ?>ҳ�� ת���� 
                <input name="page" type="text" size="3" value="<? echo $page;?>">ҳ 
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