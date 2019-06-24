#include "vcl.h"
#pragma hdrstop  
#include "UFormaElementaSprDepartmentCF.h"
#include "UFormaElementaSprDepartmentImpl.h"

#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
TFormaElementaSprDepartmentCF::TFormaElementaSprDepartmentCF()
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
TFormaElementaSprDepartmentCF::~TFormaElementaSprDepartmentCF()
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int TFormaElementaSprDepartmentCF::kanQueryInterface(REFIID id_interface, void**ppv)
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
int TFormaElementaSprDepartmentCF::kanAddRef(void)
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int TFormaElementaSprDepartmentCF::kanRelease(void)
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int TFormaElementaSprDepartmentCF::kanCreateInstance(REFIID id_interface, void ** ppv)
{  
int result=0;  
		TFormaElementaSprDepartmentImpl * ob=new TFormaElementaSprDepartmentImpl();
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
