#include "vcl.h"
#pragma hdrstop  
#include "UDMDocSpOtrOstCF.h"   
#include "UDMDocSpOtrOstImpl.h"  
#include "IDMDocSpOtrOst.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
TDMDocSpOtrOstCF::TDMDocSpOtrOstCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
TDMDocSpOtrOstCF::~TDMDocSpOtrOstCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int TDMDocSpOtrOstCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int TDMDocSpOtrOstCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int TDMDocSpOtrOstCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int TDMDocSpOtrOstCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		TDMDocSpOtrOstImpl * ob=new TDMDocSpOtrOstImpl();  
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
