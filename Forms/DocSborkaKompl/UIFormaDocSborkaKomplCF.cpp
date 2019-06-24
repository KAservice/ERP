#include "vcl.h"
#pragma hdrstop  
#include "UIFormaDocSborkaKomplCF.h"   
#include "UIFormaDocSborkaKomplImpl.h"  
#include "IIFormaDocSborkaKompl.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
TIFormaDocSborkaKomplCF::TIFormaDocSborkaKomplCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
TIFormaDocSborkaKomplCF::~TIFormaDocSborkaKomplCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int TIFormaDocSborkaKomplCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
reinterpret_cast<IkanUnknown*>(*ppv)->kanAddRef();  
return result;  
}   
//---------------------------------------------------------------
int TIFormaDocSborkaKomplCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int TIFormaDocSborkaKomplCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int TIFormaDocSborkaKomplCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		TIFormaDocSborkaKomplImpl * ob=new TIFormaDocSborkaKomplImpl();  
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
