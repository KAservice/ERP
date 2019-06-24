#include "vcl.h"
#pragma hdrstop  
#include "UDMRegOstNomCF.h"   
#include "UDMRegOstNomImpl.h"  
#include "IDMRegOstNom.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
TDMRegOstNomCF::TDMRegOstNomCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
TDMRegOstNomCF::~TDMRegOstNomCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int TDMRegOstNomCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int TDMRegOstNomCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int TDMRegOstNomCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int TDMRegOstNomCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		TDMRegOstNomImpl * ob=new TDMRegOstNomImpl();  
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
