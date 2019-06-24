#include "vcl.h"
#pragma hdrstop  
#include "UDMXTableIsmCF.h"   
#include "UDMXTableIsmImpl.h"  
#include "IDMXTableIsm.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
TDMXTableIsmCF::TDMXTableIsmCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
TDMXTableIsmCF::~TDMXTableIsmCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int TDMXTableIsmCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int TDMXTableIsmCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int TDMXTableIsmCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int TDMXTableIsmCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		TDMXTableIsmImpl * ob=new TDMXTableIsmImpl();  
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
