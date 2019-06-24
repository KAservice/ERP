#include "vcl.h"
#pragma hdrstop  
#include "UFormaReportGoodsReportCF.h"   
#include "UFormaReportGoodsReportImpl.h"  
#pragma package(smart_init)
extern int NumObject;  
//---------------------------------------------------------------
TFormaReportGoodsReportCF::TFormaReportGoodsReportCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
TFormaReportGoodsReportCF::~TFormaReportGoodsReportCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int TFormaReportGoodsReportCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int TFormaReportGoodsReportCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int TFormaReportGoodsReportCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int TFormaReportGoodsReportCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		TFormaReportGoodsReportImpl * ob=new TFormaReportGoodsReportImpl();  
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
