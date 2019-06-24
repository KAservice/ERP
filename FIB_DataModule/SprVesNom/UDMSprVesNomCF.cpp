#include <vcl.h>
#pragma hdrstop
#include "UDMSprVesNomCF.h"   
#include "UDMSprVesNomImpl.h"  
#include "IDMSprVesNom.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
TDMSprVesNomCF::TDMSprVesNomCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
TDMSprVesNomCF::~TDMSprVesNomCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int TDMSprVesNomCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int TDMSprVesNomCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int TDMSprVesNomCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int TDMSprVesNomCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		TDMSprVesNomImpl * ob=new TDMSprVesNomImpl();  
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
