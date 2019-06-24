#include "vcl.h"
#pragma hdrstop  
#include "UDMProgramSetupCF.h"   
#include "UDMProgramSetupImpl.h"  
#include "IDMProgramSetup.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
TDMProgramSetupCF::TDMProgramSetupCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
TDMProgramSetupCF::~TDMProgramSetupCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int TDMProgramSetupCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int TDMProgramSetupCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int TDMProgramSetupCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int TDMProgramSetupCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		TDMProgramSetupImpl * ob=new TDMProgramSetupImpl();  
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
