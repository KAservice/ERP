#include "vcl.h"
#pragma hdrstop  
#include "UFormaElementaSprKlientDopFisLCF.h"   
#include "UFormaElementaSprKlientDopFisLImpl.h"  
#include "IFormaElementaSprKlientDopFisL.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
TFormaElementaSprKlientDopFisLCF::TFormaElementaSprKlientDopFisLCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
TFormaElementaSprKlientDopFisLCF::~TFormaElementaSprKlientDopFisLCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int TFormaElementaSprKlientDopFisLCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int TFormaElementaSprKlientDopFisLCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int TFormaElementaSprKlientDopFisLCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int TFormaElementaSprKlientDopFisLCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		TFormaElementaSprKlientDopFisLImpl * ob=new TFormaElementaSprKlientDopFisLImpl();  
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
