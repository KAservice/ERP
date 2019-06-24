#include "vcl.h"
#pragma hdrstop  
#include "UFormaReportOCBRegOstNomCF.h"   
#include "UFormaReportOCBRegOstNomImpl.h"

#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
TFormaReportOCBRegOstNomCF::TFormaReportOCBRegOstNomCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
TFormaReportOCBRegOstNomCF::~TFormaReportOCBRegOstNomCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int TFormaReportOCBRegOstNomCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int TFormaReportOCBRegOstNomCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int TFormaReportOCBRegOstNomCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int TFormaReportOCBRegOstNomCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		TFormaReportOCBRegOstNomImpl * ob=new TFormaReportOCBRegOstNomImpl();  
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
