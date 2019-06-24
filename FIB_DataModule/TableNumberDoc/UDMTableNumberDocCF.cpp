#include <vcl.h>
#pragma hdrstop
#include "UDMTableNumberDocCF.h"   
#include "UDMTableNumberDocImpl.h"  
#include "IDMTableNumberDoc.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
TDMTableNumberDocCF::TDMTableNumberDocCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
TDMTableNumberDocCF::~TDMTableNumberDocCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int TDMTableNumberDocCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int TDMTableNumberDocCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int TDMTableNumberDocCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;
	return 0;
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int TDMTableNumberDocCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		TDMTableNumberDocImpl * ob=new TDMTableNumberDocImpl();  
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
