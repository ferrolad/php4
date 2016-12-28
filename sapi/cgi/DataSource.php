<?
/***********************************************************************/
/*                                                                     */
/*  FILE        :DataSource.php                                        */
/*  DATE        :2005/07/12                                            */
/*  DESCRIPTION :数据接口层/数据源（SQL-Server）                       */
/*  PROJECT     :数字租赁系统                                          */
/*                                                                     */
/***********************************************************************/


if (!isset($REALROOTPATH)) $REALROOTPATH = substr(dirname($HTTP_SERVER_VARS['SCRIPT_FILENAME']).'/', 0, -strlen('/di')-1);
if (!isset($ROOTPATH)) $ROOTPATH = substr(dirname($HTTP_SERVER_VARS['PHP_SELF']).'/',0,-strlen('/di')-1);
require_once $REALROOTPATH . '/di/di_common.php';
require_once $REALROOTPATH . '/di/DBConfig.conf';


static $m_DBH		= 0;										/* 数据库连接 */


/**********************************************************
 *  CDataSource: 数据源（SQL-Server）类
 *  实现对永久性存储数据的增加、修改、查询、删除等操作
 **********************************************************/
class CDataSource
{
	/**********************************************************
	*  Init: 初始化数据源
	*
	*  @param none
	*  @return TRUE: 成功; FALSE: 失败
	**********************************************************/
	function Init ()
	{
		global $m_Host, $m_Port, $m_User, $m_Password, $m_DBH, $m_DB_Name;
		
		if ($m_DBH == 0)				/* 尚未初始化 */
		{
			//$m_DBH = mssql_connect ($m_Host . ":" . $m_Port, $m_User, $m_Password);      /* 连接数据库 */
			$m_DBH = mssql_connect ($m_Host, $m_User, $m_Password);		/* 连接数据库 */
		}
		
		if ($m_DBH == 0)				/* 初始化失败 */
		{
			return FALSE;
		}
		else							/* 初始化成功 */
		{
		    return mssql_select_db($m_DB_Name); 						/* 选定数据库 */
		}
		
		return TRUE;
	}
	
	/**********************************************************
	*  Add: 新建一个记录
	*
	*  @param $recordtype:	记录类型名
	*  @param $record:		欲添加的记录
	*  @return TRUE: 成功; FALSE: 失败
	**********************************************************/
	function Add ($recordtype, $record)
	{
		$recordtype = 'tb_'.$recordtype;
		
		/*-- 将传入的欲添加的记录加工成sql语句: begin --*/
		$fields = "";
		$values = "";
		
		while (list ($rcrd, $rcrd_val) = each ($record))
		{
			if($rcrd == 'id')
			{
				continue;
			}
			
		    $fields = $fields . " " . $rcrd . ",";
		    $values = $values . "'" . htmlspecialchars($rcrd_val,ENT_QUOTES) . "',";
		}
		/*-- 将传入的欲添加的记录加工成sql语句: end --*/
		
		$fields = substr ($fields, 0, -1);
		$values = substr ($values, 0, -1);
		$rslt = mssql_query ("insert into " . $recordtype . " (" . $fields . ") values (" . $values . ")");

/* debug: begin */
//if ($recordtype=='tb_sale_agent') exit( "insert into " . $recordtype . " (" . $fields . ") values (" . $values . ")");
/* debug: end */

		if ($rslt > 0) 									/* 数据库查询结果返回正值 */
		{
			return TRUE;
		}
		else 											/* 数据库查询失败返回false */
		{
		    return FALSE;
		}
	}
	
	
	/**********************************************************
	*  Del: 删除指定的记录
	*
	*  @param $recordtype:	记录类型名
	*  @param $indexs:		欲删除记录的索引的数组
	*  @return TRUE: 成功; FALSE: 失败
	**********************************************************/
	function Del ($recordtype, $indexs)
	{
		global $m_DBH;
		
		$recordtype = 'tb_'.$recordtype;
		
        /*-- 一条一条地删除数据: begin --*/
        for ($i = 0; $i < count ($indexs); $i++)
        {
            /*-- 将传入的索引条件中的一条加工成sql语句: begin --*/
            $ind = "";
            while (list ($index, $index_val) = each ($indexs[$i]))
            {
                $ind = $ind . " " . $index . " = " . $index_val . " and ";
            }
            $ind = substr ($ind, 0, -5);
			/*-- 将传入的索引条件中的一条加工成sql语句: end -*/

/* debug: begin */
//if ($recordtype=='tb_sale_agent') echo "delete from " . $recordtype . " where " . $ind;
/* debug: end */

            if (!mssql_query ("delete from " . $recordtype . " where " . $ind))
            { 
                return FALSE;
            }

        }
		
		/* 一条数据都没有删除 */
		if (mssql_rows_affected($m_DBH) == 0)           
		{
		    return FALSE;
		}
		/*-- 一条一条地删除数据: end --*/
		
		return TRUE;
	}
	
	
	/**********************************************************
	*  DelByTerms: 删除符合条件的记录
	*
	*  @param $recordtype:	记录类型名
	*  @param $terms:		欲删除记录的条件数组
	*  @return TRUE: 成功; FALSE: 失败
	**********************************************************/
	function DelByTerms ($recordtype, $terms)
	{
        /*-- 将一个一个的条件拼起来: begin --*/
        $trms = "";
		$resultorder = "";
		$n = 0;
		
		$recordtype = 'tb_'.$recordtype;
		
        for ($i = 0; $i < count ($terms); ++$i)
        {

            if ($terms[$i][3] == 0)     /* 一个条件的第4个元素为0时,该条件的含义为大于第二个元素且小于第三个元素 */
            {
                if ($terms[$i][1]!==NULL) $trm1 = $terms[$i][0] . ">'" . htmlspecialchars($terms[$i][1],ENT_QUOTES) . "' and ";else $trm1 = "";
                if ($terms[$i][2]!==NULL) $trm2 = $terms[$i][0] . "<'" . htmlspecialchars($terms[$i][2],ENT_QUOTES) . "' and ";else $trm2 = "";
            }
            else if ($terms[$i][3] == 1)/* 一个条件的第4个元素为1时,该条件的含义为大等于第二个元素且小等于第三个元素 */
            {

                if ($terms[$i][1]!==NULL) $trm1 = $terms[$i][0] . ">='" . htmlspecialchars($terms[$i][1],ENT_QUOTES) . "' and ";else $trm1 = "";
                if ($terms[$i][2]!==NULL) $trm2 = $terms[$i][0] . "<='" . htmlspecialchars($terms[$i][2],ENT_QUOTES) . "' and ";else $trm2 = "";
            }
            else if ($terms[$i][3] == 2)/* 一个条件的第4个元素为2时,该条件的含义为大于第二个元素且小等于第三个元素 */
            {
                if ($terms[$i][1]!==NULL) $trm1 = $terms[$i][0] . ">'" . htmlspecialchars($terms[$i][1],ENT_QUOTES) . "' and ";else $trm1 = "";
                if ($terms[$i][2]!==NULL) $trm2 = $terms[$i][0] . "<='" . htmlspecialchars($terms[$i][2],ENT_QUOTES) . "' and ";else $trm2 = "";
            }
            else if ($terms[$i][3] == 3)/* 一个条件的第4个元素为3时,该条件的含义为大等于第二个元素且小于第三个元素 */
            {
                if ($terms[$i][1]!==NULL) $trm1 = $terms[$i][0] . ">='" . htmlspecialchars($terms[$i][1],ENT_QUOTES) . "' and ";else $trm1 = "";
                if ($terms[$i][2]!==NULL) $trm2 = $terms[$i][0] . "<'" . htmlspecialchars($terms[$i][2],ENT_QUOTES) . "' and ";else $trm2 = "";
            }
            else if ($terms[$i][3] == 4)/* 一个条件的第4个元素为4时,该条件的含义为含有第二个元素 */
            {
                $trm1 = $terms[$i][0] . " LIKE '%" . htmlspecialchars($terms[$i][1],ENT_QUOTES) . "%' and ";
                $trm2 = "";
            }

            $trms = $trms . $trm1 . $trm2;
        }
        
		$where = '';
		if ($trms != "")
		{
			$where = " where " . substr($trms, 0, -5);
		}

		$rslt = mssql_query ("delete " . $recordtype . $where);

        if ($rslt > 0)                             /* 数据库查询结果返回正值 */
        {
            return TRUE;
        }
        else                                       /* 数据库查询失败 */
        {
            return FALSE;
        }
    }
    
		
	/**********************************************************
	*  Search: 检索出满足指定条件的记录
	*
	*  @param $result:		传出结果
	*  @param $recordtype:	记录类型名
	*  @param $terms:		检索条件数组
	*  @param $orderby:		对检索结果进行排序的属性名
	*  @param $asc: 		TRUE: 升序; FALSE: 降序
	*  @param $offset:		传出的第1个记录的偏移
	*  @param $rows:		传出的记录数
	*  @return 符合条件的记录总数，-1表示失败
	**********************************************************/
	function Search (&$result, $recordtype, $terms, $orderby, $asc, $offset, $rows)
	{
        /*-- 将一个一个的条件拼起来: begin --*/
        $trms = "";
		$resultorder = "";
		$n = 0;
		
		$recordtype = 'tb_'.$recordtype;
		
        for ($i = 0; $i < count ($terms); ++$i)
        {

            if ($terms[$i][3] == 0)     /* 一个条件的第4个元素为0时,该条件的含义为大于第二个元素且小于第三个元素 */
            {
                if ($terms[$i][1]!==NULL) $trm1 = $terms[$i][0] . ">'" . htmlspecialchars($terms[$i][1],ENT_QUOTES) . "' and ";else $trm1 = "";
                if ($terms[$i][2]!==NULL) $trm2 = $terms[$i][0] . "<'" . htmlspecialchars($terms[$i][2],ENT_QUOTES) . "' and ";else $trm2 = "";
            }
            else if ($terms[$i][3] == 1)/* 一个条件的第4个元素为1时,该条件的含义为大等于第二个元素且小等于第三个元素 */
            {

                if ($terms[$i][1]!==NULL) $trm1 = $terms[$i][0] . ">='" . htmlspecialchars($terms[$i][1],ENT_QUOTES) . "' and ";else $trm1 = "";
                if ($terms[$i][2]!==NULL) $trm2 = $terms[$i][0] . "<='" . htmlspecialchars($terms[$i][2],ENT_QUOTES) . "' and ";else $trm2 = "";
            }
            else if ($terms[$i][3] == 2)/* 一个条件的第4个元素为2时,该条件的含义为大于第二个元素且小等于第三个元素 */
            {
                if ($terms[$i][1]!==NULL) $trm1 = $terms[$i][0] . ">'" . htmlspecialchars($terms[$i][1],ENT_QUOTES) . "' and ";else $trm1 = "";
                if ($terms[$i][2]!==NULL) $trm2 = $terms[$i][0] . "<='" . htmlspecialchars($terms[$i][2],ENT_QUOTES) . "' and ";else $trm2 = "";
            }
            else if ($terms[$i][3] == 3)/* 一个条件的第4个元素为3时,该条件的含义为大等于第二个元素且小于第三个元素 */
            {
                if ($terms[$i][1]!==NULL) $trm1 = $terms[$i][0] . ">='" . htmlspecialchars($terms[$i][1],ENT_QUOTES) . "' and ";else $trm1 = "";
                if ($terms[$i][2]!==NULL) $trm2 = $terms[$i][0] . "<'" . htmlspecialchars($terms[$i][2],ENT_QUOTES) . "' and ";else $trm2 = "";
            }
            else if ($terms[$i][3] == 4)/* 一个条件的第4个元素为4时,该条件的含义为含有第二个元素 */
            {
                $trm1 = $terms[$i][0] . " LIKE '%" . htmlspecialchars($terms[$i][1],ENT_QUOTES) . "%' and ";
                $trm2 = "";
            }

            $trms = $trms . $trm1 . $trm2;
        }
        
        if ($orderby !="")
        {
			$resultorder = " order by " . $orderby;
            $orderby = " order by " . $orderby;
			
			if($asc)
			{
				$orderby .= " asc";
				$resultorder .= " desc";
			}
			else
			{
				$orderby .= " desc";
				$resultorder .= " asc";
			}
        }

		$where = '';
		if ($trms != "")
		{
			$where = " where " . substr($trms, 0, -5);
		}

/* debug: begin */
//if ($recordtype=='tb_film_main_sort' or $recordtype=='tb_film_sub_sort') echo("select count(*) from " . $recordtype . $where);
/* debug: end */

		$rslt = mssql_query ("select count(*) from " . $recordtype . $where);

		$n = mssql_result($rslt, 0, 0);

		if ($n == 0)
		{
			return 0;
		}

		if ($rows == '')
		{
			$rows = $n;
		}

		if ($offset >= $n)				/* 超出记录数 */
		{
			return $n;
		}
			
		if (($offset + $rows) > $n)
		{
			$maxn = $n;
			$rows = $rows - ($offset + $rows - $n);
		}
		else
		{
			$maxn = $offset + $rows;
		}
		
        if ($trms != "")
        {
            $trms = " where " . substr($trms, 0, -5);
        }
        /*-- 将一个一个的条件拼起来: end --*/

/* debug: begin */
//if ($recordtype=='tb_sheet_p_file_consumption') echo "select * from (select top ".$rows." * from "."(select top ".$maxn." * from " . $recordtype . $trms . $orderby.") as tb_tmp0".$resultorder.") as tb_tmp1 ".$orderby;
/* debug: end */

        $rslt = mssql_query ("select * from (select top ".$rows." * from "."(select top ".$maxn." * from " . $recordtype . $trms . $orderby.") as tb_tmp0".$resultorder.") as tb_tmp1 ".$orderby);

        /*-- 将传出结果一个一个地添加到传出结果数组中: begin --*/
       	$num_rows = mssql_num_rows($rslt);
		$num_fields = mssql_num_fields($rslt);
        $result = array();

       	for($i = 0; $i < $num_rows; $i++)
		{
			for($j = 0; $j < $num_fields; $j++)
			{
				$field =  mssql_fetch_field($rslt, $j);
				$result[$i][$field->name] = mssql_result($rslt, $i, $j);
			}
		}
        /*-- 将传出结果一个一个地添加到传出结果数组中: end --*/

        if ($rslt > 0)                             /* 数据库查询结果返回正值 */
        {
            return $n;
        }
        else                                       /* 数据库查询失败 */
        {
            return -1;
        }
	}
	
	
	/**********************************************************
	*  Update: 更新一个记录
	*
	*  @param $recordtype:	记录类型名
	*  @param $index:		欲更新记录的索引
	*  @param $record:		欲更新的数据
	*  @return TRUE: 成功; FALSE: 失败
	**********************************************************/
	function Update ($recordtype, $index, $record)
	{
		/*-- 将传入的欲更新的记录加工成sql语句: begin --*/
        $rcd = "";
        
		$recordtype = 'tb_'.$recordtype;
		
        while (list ($rcrd, $rcrd_val) = each ($record))
        {
      	    $rcd = $rcd . " " . $rcrd . " " . "='" . htmlspecialchars($rcrd_val,ENT_QUOTES) . "',";
        }
        $rcd = substr ($rcd, 0, -1);
        /*-- 将传入的欲更新的记录加工成sql语句: end --*/

        if ($index != NULL)
        {
	        /*-- 将传入的索引条件加工成sql语句: begin --*/
	        $ind = "";
	        while (list ($indx, $indx_val) = each ($index))
	        {
	            $ind = $ind . $indx . "='" . $indx_val . "' and ";
	        }
	        $ind = substr ($ind, 0, -5);
	        /*-- 将传入的索引条件加工成sql语句: end --*/
	
	        $rslt = mssql_query ("update " . $recordtype . " set " . $rcd . " where " .  $ind);
	    }
	    else
	    {
	        $rslt = mssql_query ("update " . $recordtype . " set " . $rcd);
	    }
	    
/* debug: begin */
//if ($recordtype=='tb_pay_setting') echo "update " . $recordtype . " set " . $rcd . " where " .  $ind;
/* debug: end */
        if ($rslt > 0)                                 /* 数据库查询结果返回正值 */
        {
            return TRUE;
        }
        else                                           /* 数据库查询失败返回false */
        {
            return FALSE;
        }
	}

    /**********************************************************
    *  Exe: 在使用以上函数不方便时直接执行sql
    *
    *  @param $sql: SQL语句
    *  @param $result: 传出结果
    *  @return TRUE: 成功; FALSE: 失败
    **********************************************************/
    function Exe ($viewname, &$result)
    {
        $array_sql_multi=explode(';',$viewname);
        for ($i=0;$i<count($array_sql_multi);++$i)
        {
            $rslt=mssql_query($array_sql_multi[$i]);
        }

		/*-- 将传出结果一个一个地添加到传出结果数组中: begin --*/
		$result = array();
		if (is_resource ($rslt))
		{
			$num_rows = mssql_num_rows($rslt);
			$num_fields = mssql_num_fields($rslt);
			$result = array();

			for($i = 0; $i < $num_rows; $i++)
			{
				for($j = 0; $j < $num_fields; $j++)
				{
					$field =  mssql_fetch_field($rslt, $j);
					$result[$i][$field->name] = mssql_result($rslt, $i, $j);
				}
			}
		}
        /*-- 将传出结果一个一个地添加到传出结果数组中: end --*/

        if ($rslt > 0)                             /* 数据库查询结果返回正值 */
        {
            return true;
        }
        else                                           /* 数据库查询失败返回false */
        {
            return false;
        }
    }

	/**********************************************************
	*  GetTime: 获取DB Server的当前时间
	*
	*  @param $none
	*  @return unix时间戳
	**********************************************************/
	function GetTime ()
	{
		$rslt		= mssql_query ("select getdate()");
		$nowtime	= mssql_result($rslt, 0, 0);
		
		return strtotime($nowtime);
	}

	/**********************************************************
	*  GetLastID: 获取最后一次被添加的记录的id
	*
	*  @param none
	*  @return 最后一次被添加的记录的id
	**********************************************************/
	function GetLastID ()
	{
		$rslt		= mssql_query ("select @@IDENTITY");
		$lastid		= mssql_result($rslt, 0, 0);
		
		return $lastid;
	}
}


$g_DataSource = new CDataSource();
$g_DataSource->Init();


/************************************************
 * @ DataSource.php v1.0 log @
 *
 * Revision 1.0.0.0     RD010     2005/07/16
 * create file
 * 
 ***********************************************/
?>