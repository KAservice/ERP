#include "vcl.h"
#pragma hdrstop  
#include "UHOT_FormaReportRasmK_SCF.h"   
#include "UHOT_FormaReportRasmK_SImpl.h"

#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
THOT_FormaReportRasmK_SCF::THOT_FormaReportRasmK_SCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
THOT_FormaReportRasmK_SCF::~THOT_FormaReportRasmK_SCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int THOT_FormaReportRasmK_SCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int THOT_FormaReportRasmK_SCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int THOT_FormaReportRasmK_SCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int THOT_FormaReportRasmK_SCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		THOT_FormaReportRasmK_SImpl * ob=new THOT_FormaReportRasmK_SImpl();  
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
