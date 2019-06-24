#include "vcl.h"
#pragma hdrstop  
#include "UDMUserSetupCF.h"   
#include "UDMUserSetupImpl.h"  
#include "IDMUserSetup.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
TDMUserSetupCF::TDMUserSetupCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
TDMUserSetupCF::~TDMUserSetupCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int TDMUserSetupCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int TDMUserSetupCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int TDMUserSetupCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;
	return 0;
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int TDMUserSetupCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		TDMUserSetupImpl * ob=new TDMUserSetupImpl();  
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
