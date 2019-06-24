#include "vcl.h"
#pragma hdrstop
#include "UDMQueryUpdateCF.h"   
#include "UDMQueryUpdateImpl.h"  
#include "IDMQueryUpdate.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
TDMQueryUpdateCF::TDMQueryUpdateCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
TDMQueryUpdateCF::~TDMQueryUpdateCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int TDMQueryUpdateCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int TDMQueryUpdateCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int TDMQueryUpdateCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;
	return 0;
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int TDMQueryUpdateCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		TDMQueryUpdateImpl * ob=new TDMQueryUpdateImpl();  
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
