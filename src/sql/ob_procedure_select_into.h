#ifndef OCEANBASE_SQL_OB_PROCEDURE_SELECT_INTO_H
#define OCEANBASE_SQL_OB_PROCEDURE_SELECT_INTO_H
#include "sql/ob_single_child_phy_operator.h"
#include "ob_sql_session_info.h"
#include "common/dlist.h"
namespace oceanbase
{
	namespace sql
	{
		class ObPhysicalPlan;
		class ObProcedureSelectInto : public ObSingleChildPhyOperator
		{
		public:
			ObProcedureSelectInto();
			virtual ~ObProcedureSelectInto();
			virtual void reset();
			virtual void reuse();
			virtual int open();
			virtual int close();
			virtual ObPhyOperatorType get_type() const
			{
				return PHY_PROCEDURE_SELECT_INTO;
			}
			virtual int64_t to_string(char* buf, const int64_t buf_len) const;
			virtual int get_row_desc(const common::ObRowDesc *&row_desc) const;
			virtual int get_next_row(const common::ObRow *&row);

			int add_variable(ObString &var);/*添加一个变量*/

		private:
			//disallow copy
			ObProcedureSelectInto(const ObProcedureSelectInto &other);
			ObProcedureSelectInto& operator=(const ObProcedureSelectInto &other);
			//function members

		private:
			ObArray<ObString> variables_;/*select into定义变量列表*/

		};



	}
}

#endif



