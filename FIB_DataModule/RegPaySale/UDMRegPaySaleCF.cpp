#include "vcl.h"
#pragma hdrstop  
#include "UDMRegPaySaleCF.h"   
#include "UDMRegPaySaleImpl.h"  
#include "IDMRegPaySale.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
TDMRegPaySaleCF::TDMRegPaySaleCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
TDMRegPaySaleCF::~TDMRegPaySaleCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int TDMRegPaySaleCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int TDMRegPaySaleCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int TDMRegPaySaleCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int TDMRegPaySaleCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		TDMRegPaySaleImpl * ob=new TDMRegPaySaleImpl();  
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
