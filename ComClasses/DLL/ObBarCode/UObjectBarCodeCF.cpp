#pragma hdrstop  
#include "UObjectBarCodeCF.h"   
#include "UObjectBarCodeImpl.h"  
#include "IObjectBarCode.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
TObjectBarCodeCF::TObjectBarCodeCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
TObjectBarCodeCF::~TObjectBarCodeCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int TObjectBarCodeCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int TObjectBarCodeCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int TObjectBarCodeCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;
	return 0;
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int TObjectBarCodeCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		TObjectBarCodeImpl * ob=new TObjectBarCodeImpl();  
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
