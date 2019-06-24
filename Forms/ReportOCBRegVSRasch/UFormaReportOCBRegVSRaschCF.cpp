#include "vcl.h"
#pragma hdrstop  
#include "UFormaReportOCBRegVSRaschCF.h"   
#include "UFormaReportOCBRegVSRaschImpl.h"  

#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
TFormaReportOCBRegVSRaschCF::TFormaReportOCBRegVSRaschCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
TFormaReportOCBRegVSRaschCF::~TFormaReportOCBRegVSRaschCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int TFormaReportOCBRegVSRaschCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int TFormaReportOCBRegVSRaschCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int TFormaReportOCBRegVSRaschCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int TFormaReportOCBRegVSRaschCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		TFormaReportOCBRegVSRaschImpl * ob=new TFormaReportOCBRegVSRaschImpl();  
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
