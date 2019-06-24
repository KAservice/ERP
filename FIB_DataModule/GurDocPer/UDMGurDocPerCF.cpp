#include "vcl.h"
#pragma hdrstop  
#include "UDMGurDocPerCF.h"   
#include "UDMGurDocPerImpl.h"  
#include "IDMGurDocPer.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
TDMGurDocPerCF::TDMGurDocPerCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
TDMGurDocPerCF::~TDMGurDocPerCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int TDMGurDocPerCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int TDMGurDocPerCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int TDMGurDocPerCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int TDMGurDocPerCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		TDMGurDocPerImpl * ob=new TDMGurDocPerImpl();  
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
