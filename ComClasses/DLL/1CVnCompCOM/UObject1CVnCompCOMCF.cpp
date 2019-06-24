
#pragma hdrstop  
#include "UObject1CVnCompCOMCF.h"
#include "UObject1CVnCompCOMImpl.h"
#include "IObject1CVnCompCOM.h"
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
TObject1CVnCompCOMCF::TObject1CVnCompCOMCF()
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
TObject1CVnCompCOMCF::~TObject1CVnCompCOMCF()
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int TObject1CVnCompCOMCF::kanQueryInterface(REFIID id_interface, void**ppv)
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
int TObject1CVnCompCOMCF::kanAddRef(void)
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int TObject1CVnCompCOMCF::kanRelease(void)
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int TObject1CVnCompCOMCF::kanCreateInstance(REFIID id_interface, void ** ppv)
{  
int result=0;  
		TObject1CVnCompCOMImpl * ob=new TObject1CVnCompCOMImpl();
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
