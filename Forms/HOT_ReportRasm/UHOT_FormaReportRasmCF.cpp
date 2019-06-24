#include "vcl.h"
#pragma hdrstop  
#include "UHOT_FormaReportRasmCF.h"   
#include "UHOT_FormaReportRasmImpl.h"  

#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
THOT_FormaReportRasmCF::THOT_FormaReportRasmCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
THOT_FormaReportRasmCF::~THOT_FormaReportRasmCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int THOT_FormaReportRasmCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int THOT_FormaReportRasmCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int THOT_FormaReportRasmCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int THOT_FormaReportRasmCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		THOT_FormaReportRasmImpl * ob=new THOT_FormaReportRasmImpl();  
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
