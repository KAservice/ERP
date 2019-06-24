#include "vcl.h"
#pragma hdrstop  
#include "UDMDocRegAdvCustCF.h"   
#include "UDMDocRegAdvCustImpl.h"  
#include "IDMDocRegAdvCust.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
TDMDocRegAdvCustCF::TDMDocRegAdvCustCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
TDMDocRegAdvCustCF::~TDMDocRegAdvCustCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int TDMDocRegAdvCustCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int TDMDocRegAdvCustCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int TDMDocRegAdvCustCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int TDMDocRegAdvCustCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		TDMDocRegAdvCustImpl * ob=new TDMDocRegAdvCustImpl();  
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
