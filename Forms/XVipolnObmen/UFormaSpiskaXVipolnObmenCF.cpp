#include "vcl.h"
#pragma hdrstop  
#include "UFormaSpiskaXVipolnObmenCF.h"   
#include "UFormaSpiskaXVipolnObmenImpl.h"  
#include "IFormaSpiskaXVipolnObmen.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
TFormaSpiskaXVipolnObmenCF::TFormaSpiskaXVipolnObmenCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
TFormaSpiskaXVipolnObmenCF::~TFormaSpiskaXVipolnObmenCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int TFormaSpiskaXVipolnObmenCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int TFormaSpiskaXVipolnObmenCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int TFormaSpiskaXVipolnObmenCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int TFormaSpiskaXVipolnObmenCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		TFormaSpiskaXVipolnObmenImpl * ob=new TFormaSpiskaXVipolnObmenImpl();  
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
