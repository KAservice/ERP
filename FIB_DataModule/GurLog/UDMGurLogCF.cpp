#include "vcl.h"
#pragma hdrstop  
#include "UDMGurLogCF.h"   
#include "UDMGurLogImpl.h"  
#include "IDMGurLog.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
TDMGurLogCF::TDMGurLogCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
TDMGurLogCF::~TDMGurLogCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int TDMGurLogCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int TDMGurLogCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int TDMGurLogCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int TDMGurLogCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		TDMGurLogImpl * ob=new TDMGurLogImpl();  
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
