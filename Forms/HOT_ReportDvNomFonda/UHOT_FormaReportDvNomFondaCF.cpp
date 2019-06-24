#include "vcl.h"
#pragma hdrstop  
#include "UHOT_FormaReportDvNomFondaCF.h"   
#include "UHOT_FormaReportDvNomFondaImpl.h"

#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
THOT_FormaReportDvNomFondaCF::THOT_FormaReportDvNomFondaCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
THOT_FormaReportDvNomFondaCF::~THOT_FormaReportDvNomFondaCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int THOT_FormaReportDvNomFondaCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int THOT_FormaReportDvNomFondaCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int THOT_FormaReportDvNomFondaCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int THOT_FormaReportDvNomFondaCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		THOT_FormaReportDvNomFondaImpl * ob=new THOT_FormaReportDvNomFondaImpl();  
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
