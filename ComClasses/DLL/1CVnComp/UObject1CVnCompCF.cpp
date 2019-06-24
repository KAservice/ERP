
#pragma hdrstop  
#include "UObject1CVnCompCF.h"   
#include "UObject1CVnCompImpl.h"  
#include "IObject1CVnComp.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
TObject1CVnCompCF::TObject1CVnCompCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
TObject1CVnCompCF::~TObject1CVnCompCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int TObject1CVnCompCF::kanQueryInterface(REFIID id_interface, void**ppv)
{    
int result=0;
//REFIID inter=id_interface;
//StringFromIID(inter,IID_IkanClassFactory);

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
	//*ppv=NULL;
	result=0;
	*ppv=static_cast<IkanClassFactory*> (this);
	result=-1;
	return result;  
	} 
kanAddRef();  
return result;  
}   
//---------------------------------------------------------------
int TObject1CVnCompCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int TObject1CVnCompCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int TObject1CVnCompCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		TObject1CVnCompImpl * ob=new TObject1CVnCompImpl();  
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
