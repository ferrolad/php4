<?
/***********************************************************************/
/*                                                                     */
/*  FILE        :Shop.php                                              */
/*  DATE        :2005/07/17                                            */
/*  DESCRIPTION :实体层/表单/门店资料                                  */
/*  PROJECT     :数字租赁系统                                          */
/*                                                                     */
/***********************************************************************/


if (!isset($REALROOTPATH)) $REALROOTPATH = substr(dirname($HTTP_SERVER_VARS['SCRIPT_FILENAME']).'/', 0, -strlen('/en/BOD')-1);
if (!isset($ROOTPATH)) $ROOTPATH = substr(dirname($HTTP_SERVER_VARS['PHP_SELF']).'/',0,-strlen('/en/BOD')-1);
require_once $REALROOTPATH . '/en/en_common.php';
require_once $REALROOTPATH . '/di/DataSource.php';


/**********************************************************
 *  CShop: 门店资料
 *  一条门店资料的详细资料
 **********************************************************/
class CShop
{
	/*-- 基本信息 --*/            
	var $id;						/* 门店编号                  */
	var $name;						/* 门店名称                  */
	var $country;					/* 国家                      */
	var $prov;						/* 省份/州                   */
	var $city;						/* 城市                      */
	var $addr;						/* 地址                      */
	var $zip;						/* 邮编                      */
	var $tel;						/* 电话                      */
	var $fax;						/* 传真                      */
	var $website;					/* 网址                      */
	var $logo;						/* LOGO                      */
	var $bank_account;				/* 银行账号                  */
	var $tax_no;					/* 税号                      */
	var $credit_no;					/* 信用卡号                  */
	var $contact;					/* 联系人                    */
	var $mobile;					/* 手机                      */
	var $email;						/* 电子邮件                  */
	var $userid;					/* 登录名                    */
	var $passwd;					/* 登录密码                  */
	var $sa_id;						/* 所属销售代理商            */
	var $status;					/* 状态0: 活动1: 冻结2: 停止 */
	var $notes;						/* 备注                      */
	var $create_date;				/* 创建日期                  */

	/*-- 关联信息 --*/
	var $sa_name;					/* 所属销售代理商姓名        */
}


/**********************************************************
 *  CShopSet: 门店资料集合类
 *  实现对门店资料的增加、修改、查询、删除等操作
 **********************************************************/
class CShopSet
{
	/**********************************************************
	*  Add: 添加一个门店资料
	*
	*  @param $object: 一个门店资料的实例
	*  @return TRUE: 成功; FALSE: 失败
	**********************************************************/
	function Add ($object)
	{
		global $g_DataSource;
		
		if ($object->passwd != NULL)
		{
			$object->passwd = md5($object->passwd);			 /* 对密码进行hash */
		}
		
		if (get_class($object) ==  strtolower("CShop"))    /* 判断传入对象是否符合要求 */
		{
			/*-- 将对象数据转化成数组数据: begin --*/
			$obj_vars = get_object_vars ($object);
			while (list($obj_key, $obj_val) = each ($obj_vars))
			{
				if ($obj_val !== null)                       /* 对$obj_val进行严格比对 */
				{
					$object_array[$obj_key] = $obj_val;
				}
			}
			/*-- 将对象数据转化成数组数据: end --*/
			
			if (!$g_DataSource->Add ( shop, $object_array))
			{  
				return FALSE;
			}
			
			return TRUE;
		}
		else
		{
			return FALSE;
		}
	}
	
	
	/**********************************************************
	*  Del: 删除一批门店资料
	*
	*  @param $indexs: 欲删除的门店资料编号的数组
	*  @return TRUE: 成功; FALSE: 失败
	**********************************************************/
	function Del ($indexs)
	{
		global $g_DataSource;
		
		for ($i = 0; $i < count ($indexs); $i++)
		{
			$ids[$i] = array('id' => $indexs[$i]);
		}
		
		if (!$g_DataSource->Del (shop, $ids))
		{
			return FALSE;
		}
		
		return TRUE;
	}
	
	
	/**********************************************************
	*  Search: 检索出满足指定条件的门店资料
	*
	*  @param $objects: 传出的CShop实例的数组
	*  @param $terms:   检索条件数组
	*  @param $orderby: 对检索结果进行排序的属性名
	*  @param $asc: 	TRUE: 升序; FALSE: 降序
	*  @param $offset:	传出的第1个实例的偏移
	*  @param $rows:	传出的实例数
	*  @return 符合条件的门店资料总数，-1表示失败
	**********************************************************/
	function Search (&$objects, $terms, $orderby, $asc = TRUE, $offset = 0, $rows = 20)
	{
		global $g_DataSource;
		
		if ($orderby == '')
		{
			$orderby = 'id';
		}
		
		$n = $g_DataSource->Search (&$result, shop, $terms, $orderby, $asc, $offset, $rows);
		if ($n > 0)				/* 搜索成功 */
		{
			for ($i = 0; $i < count ($result); ++$i)                    /* 将结果数组里的数据转移到结果对象数组 */
			{
				$objects[$i] = new CShop();
				
				while (list($rslt_key, $rslt_val) = each ($result[$i]))
				{
					$objects[$i]->$rslt_key = $rslt_val;
				}

				/*-- 处理关联信息: begin --*/
				$t = array();
				$t[0] = array('id', $objects[$i]->sa_id, $objects[$i]->sa_id, 1);
				$m = $g_DataSource->Search (&$sas, 'sale_agent', $t, '', TRUE, 0, '');
				
				if ($m > 0)
				{
					$objects[$i]->sa_name = $sas[0]['name'];
				}
				/*-- 处理关联信息: end --*/
			}
		}
		
		return $n;
    }


	/**********************************************************
	*  Update: 更新一个门店资料
	*
	*  @param $object: 欲更新的门店资料（CShop的实例）。无需更新的属性为NULL
	*  @return TRUE: 成功; FALSE: 失败
	**********************************************************/
	function Update ($object)
	{
		global $g_DataSource;
		
        if ($object->passwd != NULL)
        {
        	$object->passwd = md5($object->passwd);			 /* 对密码进行hash */
        }
        
		if (get_class($object) ==  strtolower("CShop"))    /* 判断传入对象是否符合要求 */
		{
	
			/*-- 将对象数据转化成数组数据: begin --*/
			$obj_vars = get_object_vars ($object);
			while (list($obj_key, $obj_val) = each ($obj_vars))
			{
				if ($obj_val !== null)                       /* 对$obj_val进行严格比对 */
				{
					if ($obj_key != 'id')
					{
						$object_array[$obj_key] = $obj_val;
					}
				}
			}
			/*-- 将对象数据转化成数组数据: end --*/
	
			$terms['id'] = $object->id;
			if (!$g_DataSource->Update ('shop', $terms, $object_array))
			{  
			 return FALSE;
			}
			
			return TRUE;
		}
		else
		{
			return FALSE;
		}
	}
}


/************************************************
 * @ Shop.php v1.0 log @
 *
 * Revision 1.0.0.0     RD051     2005/07/17
 * create file
 * 
 ***********************************************/
?>