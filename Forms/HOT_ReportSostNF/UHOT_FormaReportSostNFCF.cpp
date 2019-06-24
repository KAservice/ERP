#include "vcl.h"
#pragma hdrstop  
#include "UHOT_FormaReportSostNFCF.h"   
#include "UHOT_FormaReportSostNFImpl.h"

#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
THOT_FormaReportSostNFCF::THOT_FormaReportSostNFCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
THOT_FormaReportSostNFCF::~THOT_FormaReportSostNFCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int THOT_FormaReportSostNFCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int THOT_FormaReportSostNFCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int THOT_FormaReportSostNFCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int THOT_FormaReportSostNFCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		THOT_FormaReportSostNFImpl * ob=new THOT_FormaReportSostNFImpl();  
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
