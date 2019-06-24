#include "vcl.h"
#pragma hdrstop  
#include "USR_FormaOstatkiTovarovCF.h"   
#include "USR_FormaOstatkiTovarovImpl.h"

#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
TSR_FormaOstatkiTovarovCF::TSR_FormaOstatkiTovarovCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
TSR_FormaOstatkiTovarovCF::~TSR_FormaOstatkiTovarovCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int TSR_FormaOstatkiTovarovCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int TSR_FormaOstatkiTovarovCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int TSR_FormaOstatkiTovarovCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int TSR_FormaOstatkiTovarovCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		TSR_FormaOstatkiTovarovImpl * ob=new TSR_FormaOstatkiTovarovImpl();  
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
