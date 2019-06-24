#include "vcl.h"
#pragma hdrstop  
#include "UHOT_FormaSpiskaSprNFCF.h"   
#include "UHOT_FormaSpiskaSprNFImpl.h"  
#include "IHOT_FormaSpiskaSprNF.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
THOT_FormaSpiskaSprNFCF::THOT_FormaSpiskaSprNFCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
THOT_FormaSpiskaSprNFCF::~THOT_FormaSpiskaSprNFCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int THOT_FormaSpiskaSprNFCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int THOT_FormaSpiskaSprNFCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int THOT_FormaSpiskaSprNFCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int THOT_FormaSpiskaSprNFCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		THOT_FormaSpiskaSprNFImpl * ob=new THOT_FormaSpiskaSprNFImpl();  
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
