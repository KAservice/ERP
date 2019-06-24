#include <vcl.h>
#pragma hdrstop
#include "UDMSprProjectCF.h"   
#include "UDMSprProjectImpl.h"  
#include "IDMSprProject.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
TDMSprProjectCF::TDMSprProjectCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
TDMSprProjectCF::~TDMSprProjectCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int TDMSprProjectCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int TDMSprProjectCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int TDMSprProjectCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;
	return 0;
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int TDMSprProjectCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		TDMSprProjectImpl * ob=new TDMSprProjectImpl();  
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
