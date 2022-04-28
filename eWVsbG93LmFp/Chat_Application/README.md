# Chat application

Design a Chat Application. 

Discussion on Schema and public APIs.

Not have to code but explain the entire flow and data structures used.


## Features
1. Single Chat ( one to one messaging )
2. Group Chat ( one to many messaging )


### Micro features
- Expecting to send a message in both. DONE
- Read messages. DONE
- No edit of messages allowed.
- Delete a given message, it should be soft delete. Recipient must know that message is deleted. 
- Message data format is text. DONE

- When app is opened, fetch latest 50 conversations. DONE


### Assumptions

- All UI is already implemented, only need to define APIs to call and fetch response.
- There is a global list of users whose API is already present.

-------

## Application Structure

Design starts.


### APIs

#### Fetch Conversations
- Returns list of conversations in range `conv_start` to `conv_end` for that user.
- Params
    - `convStart` : start page of conversations
    - `convEnd` : end page of conversations 
    - `userId` : User id of current user

- Returns
    - List of conversations.

- API process:
    - From `userId` get `User` object.
    - From `User` get `Entity`s where fromUser = `User` object.
    - Get `EntityList` of all entities using `Entity` object.
    - get all messages where from=`User` and to=`EntityList`
    - sort `Message`s based on descending order on `when`
    - return first `convStart + (convEnd-convStart)`

-------------

### Schema

#### Message
- id :          [INT]
- content :     [TEXT]
- from :        [User]
- to :          [Entity]
- when :        [TIME]
- INDEX(from,to)
- INDEX(when)


#### Entity
- id :          [INT]
- fromUser :    [User]
- INDEX(fromUser)


#### EntityList
- entityId :    [Entity]
- userID :      [User]
- INDEX(entityId)


#### User
- id :        [INT]
- name :      [TEXT]
- INDEX(id)


--------

### Sample Usecase and its data in Schema

- When User 6 send messages to Users( 1,2,3,4 )
  - A new `Entity` object is created: `Entity{0,6}` where `0` is `Entity.id` and `6` is `User.id`.


### DB entries for this case.

#### Entity

`id: 0        fromUser: 0`

#### EntityList

`entityId: 0  userId: 1`

`entityId: 0  userId: 2`

`entityId: 0  userId: 3`

`entityId: 0  userId: 4`


