#include "vcl.h"
#pragma hdrstop  
#include "UFormaReportKalkKartaCF.h"   
#include "UFormaReportKalkKartaImpl.h"  

#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
TFormaReportKalkKartaCF::TFormaReportKalkKartaCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
TFormaReportKalkKartaCF::~TFormaReportKalkKartaCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int TFormaReportKalkKartaCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int TFormaReportKalkKartaCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int TFormaReportKalkKartaCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int TFormaReportKalkKartaCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		TFormaReportKalkKartaImpl * ob=new TFormaReportKalkKartaImpl();  
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
