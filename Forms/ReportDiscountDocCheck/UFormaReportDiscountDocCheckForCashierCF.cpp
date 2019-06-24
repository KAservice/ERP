#include "vcl.h"
#pragma hdrstop  
#include "UFormaReportDiscountDocCheckForCashierCF.h"   
#include "UFormaReportDiscountDocCheckForCashierImpl.h"

#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
TFormaReportDiscountDocCheckForCashierCF::TFormaReportDiscountDocCheckForCashierCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
TFormaReportDiscountDocCheckForCashierCF::~TFormaReportDiscountDocCheckForCashierCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int TFormaReportDiscountDocCheckForCashierCF::kanQueryInterface(REFIID id_interface, void**ppv)  
{    
int result=0;  
if (id_interface==IID_IkanUnknown) 
	{  
	*ppv=static_cast<IkanUnknown*> (this);  
	result=-1;  
	} 
else if (id_interface==IID_IkanClassFactory) 
	{  
	*ppv=static_cast<IkanClassFactory*> (this); 
	result=-1; 
	} 
else  
	{   
	*ppv=NULL;  
	result=0;  
	return result;  
	} 
kanAddRef();
return result;  
}   
//---------------------------------------------------------------
int TFormaReportDiscountDocCheckForCashierCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int TFormaReportDiscountDocCheckForCashierCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int TFormaReportDiscountDocCheckForCashierCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		TFormaReportDiscountDocCheckForCashierImpl * ob=new TFormaReportDiscountDocCheckForCashierImpl();  
		if (ob->kanQueryInterface(id_interface, ppv)==-1)   
			{       
			result=-1;  
			}    
		else     
			{           
			delete ob;   
			result=0;   
			}      
return result;  
}       
//---------------------------------------------------------------
