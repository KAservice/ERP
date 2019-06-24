#include <vcl.h>
#pragma hdrstop
#include "UDMSprPodrCF.h"   
#include "UDMSprPodrImpl.h"  
#include "IDMSprPodr.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
TDMSprPodrCF::TDMSprPodrCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
TDMSprPodrCF::~TDMSprPodrCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int TDMSprPodrCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int TDMSprPodrCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int TDMSprPodrCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;
	return 0;
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int TDMSprPodrCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		TDMSprPodrImpl * ob=new TDMSprPodrImpl();  
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
