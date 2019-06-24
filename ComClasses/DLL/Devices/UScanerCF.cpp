#include "vcl.h"
#pragma hdrstop  
#include "UScanerCF.h"   
#include "UScanerImpl.h"  
#include "IScaner.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
TScanerCF::TScanerCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
TScanerCF::~TScanerCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int TScanerCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int TScanerCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int TScanerCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;
	return 0;
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int TScanerCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		TScanerImpl * ob=new TScanerImpl();  
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
