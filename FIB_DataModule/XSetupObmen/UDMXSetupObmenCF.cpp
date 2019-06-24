#include "vcl.h"
#pragma hdrstop  
#include "UDMXSetupObmenCF.h"   
#include "UDMXSetupObmenImpl.h"  
#include "IDMXSetupObmen.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
TDMXSetupObmenCF::TDMXSetupObmenCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
TDMXSetupObmenCF::~TDMXSetupObmenCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int TDMXSetupObmenCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int TDMXSetupObmenCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int TDMXSetupObmenCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int TDMXSetupObmenCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		TDMXSetupObmenImpl * ob=new TDMXSetupObmenImpl();  
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
