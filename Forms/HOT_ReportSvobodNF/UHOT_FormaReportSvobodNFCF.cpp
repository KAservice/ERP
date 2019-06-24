#include "vcl.h"
#pragma hdrstop  
#include "UHOT_FormaReportSvobodNFCF.h"   
#include "UHOT_FormaReportSvobodNFImpl.h"

#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
THOT_FormaReportSvobodNFCF::THOT_FormaReportSvobodNFCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
THOT_FormaReportSvobodNFCF::~THOT_FormaReportSvobodNFCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int THOT_FormaReportSvobodNFCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int THOT_FormaReportSvobodNFCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int THOT_FormaReportSvobodNFCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int THOT_FormaReportSvobodNFCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		THOT_FormaReportSvobodNFImpl * ob=new THOT_FormaReportSvobodNFImpl();  
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
